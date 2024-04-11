#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <stack>

using namespace std;

int m,n,counter,sccs;
char wordC[500001];
char wordC2[500001];
string word,word2;
map<string,int> ids;
int rs[300000];
int lens[300000];
int essay[100000];
vector<int> adj[300000];
int visited[300000];
int num[300000];
int low[300000];
int which[300000];
stack<int> scc;
int best[300000];
vector<int> sccAdj[300000];

void dfs(int x) {
    num[x] = counter;
    low[x] = counter;
    counter+=1;
    scc.push(x);
    visited[x] = 1;
    for (int i=0;i<adj[x].size();i++) {
        if (!num[adj[x][i]]) dfs(adj[x][i]);
        if (visited[adj[x][i]]) low[x] = min(low[x],low[adj[x][i]]);
    }
    if (low[x]==num[x]) {
        best[sccs] = x;
        while (true) {
            int v = scc.top();
            scc.pop();
            visited[v] = 0;
            which[v] = sccs;
            if (rs[v]<rs[best[sccs]] || (rs[v]==rs[best[sccs]] && lens[v]<lens[best[sccs]])) best[sccs] = v;
            if (x==v) break;
        }
        sccs+=1;
    }
}

void findBest(int x) {
    visited[x] = 1;
    for (int i=0;i<sccAdj[x].size();i++) {
        int next = sccAdj[x][i];
        if (!visited[next]) findBest(next);
        if (rs[best[next]]<rs[best[x]] || (rs[best[next]]==rs[best[x]] && lens[best[next]]<lens[best[x]])) best[x] = best[next];
    }
}

int main() {
    scanf("%d",&m);
    for (int i=0;i<m;i++) {
        scanf(" %s",&wordC);
        word = string(wordC);
        for (int j=0;j<word.size();j++) if (word[j]<='Z') word[j] = word[j]-'A'+'a';
        if (!ids.count(word)) {
            ids[word] = ids.size()-1;
            for (int j=0;j<word.size();j++) if (word[j]=='r' || word[j]=='R') rs[ids[word]]+=1;
            lens[ids[word]] = word.size();
        }
        essay[i] = ids[word];
    }
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf(" %s %s",&wordC,&wordC2);
        word = string(wordC); word2 = string(wordC2);
        for (int j=0;j<word.size();j++) if (word[j]<='Z') word[j] = word[j]-'A'+'a';
        for (int j=0;j<word2.size();j++) if (word2[j]<='Z') word2[j] = word2[j]-'A'+'a';
        if (!ids.count(word)) {
            ids[word] = ids.size()-1;
            for (int j=0;j<word.size();j++) if (word[j]=='r' || word[j]=='R') rs[ids[word]]+=1;
            lens[ids[word]] = word.size();
        }
        if (!ids.count(word2)) {
            ids[word2] = ids.size()-1;
            for (int j=0;j<word2.size();j++) if (word2[j]=='r' || word2[j]=='R') rs[ids[word2]]+=1;
            lens[ids[word2]] = word2.size();
        }
        adj[ids[word]].push_back(ids[word2]);
    }
    counter = 1;
    sccs = 0;
    for (int i=0;i<ids.size();i++) if (!num[i]) dfs(i);
    for (int i=0;i<ids.size();i++) for (int j=0;j<adj[i].size();j++) sccAdj[which[i]].push_back(which[adj[i][j]]);
    for (int i=0;i<sccs;i++) visited[i] = 0;
    for (int i=0;i<sccs;i++) if (!visited[i]) findBest(i);
    int totalR = 0;
    long long totalLen = 0;
    for (int i=0;i<m;i++) {
        totalR+=rs[best[which[essay[i]]]];
        totalLen+=lens[best[which[essay[i]]]];
    }
    printf("%d %I64d\n",totalR,totalLen);

    return 0;
}