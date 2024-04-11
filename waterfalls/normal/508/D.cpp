#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n;
char s[4];
multiset<int> adj[62*62];
int in[62*62];
vector<char> ans;

int g(char a) {
    if (a<='9') return a-'0';
    else if (a<='Z') return a-'A'+10;
    else return a-'a'+36;
}

int f(char a, char b) { return 62*g(a)+g(b); }

char h(int a) {
    if (a<10) return (char) (a+'0');
    else if (a<36) return (char) (a-10+'A');
    else return (char) (a-36+'a');
}

void dfs(int x) {
    while (adj[x].size()>0) {
        int i = *(adj[x].begin());
        adj[x].erase(adj[x].begin());
        dfs(i);
    }
    ans.push_back(h(x/62));
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf(" %s",&s);
        adj[f(s[1],s[2])].insert(f(s[0],s[1]));
        in[f(s[0],s[1])]+=1;
    }
    int odds = 0;
    int which = 0;
    int ok = 1;
    int bad = 0;
    for (int i=0;i<62*62;i++) {
        if (abs((int) adj[i].size()-in[i])>1) ok = 0;
        if (adj[i].size()!=in[i]) bad+=1;
        if ((int) adj[i].size()-in[i]==1) {
            odds+=1;
            which = i;
        }
    }
    if (odds) {
        dfs(which);
        ans.push_back(h(which%62));
    } else {
        for (int i=0;i<62*62;i++) {
            if (adj[i].size()>0) {
                dfs(i);
                ans.push_back(h(i%62));
                break;
            }
        }
    }
    if (ans.size()==n+2 && ok && bad<=2) {
        printf("YES\n");
        for (int i=0;i<n+2;i++) printf("%c",ans[i]);
        printf("\n");
    } else printf("NO\n");
}