#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> lis[510];
int st[510], ed[510];
int tc;

vector<int> par;
vector<int> cyc;

bool dfs(int here, bool typ) {
    //if (typ) printf("%d!\n",here);
    par.push_back(here);
    st[here] = tc++;
    for (int &there: lis[here]){
        //printf("%d : %d, %d??\n",there,st[there],ed[there]);
        if (st[there]<0) {
            if (dfs(there,typ)) return true;
        }
        else if (ed[there]<0) {
            if (!typ) return true;
            while(par.back()!=there) {
                cyc.push_back(par.back());
                par.pop_back();
            }
            cyc.push_back(par.back());
            reverse(cyc.begin(),cyc.end());
            return true;
        }
    }
    ed[here] = tc++;
    par.pop_back();
    return false;
}

bool dfs(int here) {return dfs(here,1);}

bool excyc() {
    int i;
    par.clear();
    memset(st,-1,sizeof(st));
    memset(ed,-1,sizeof(ed));
    tc = 0;
    for (i=1;i<=n;i++) {
        if (st[i]<0) {
            if (dfs(i,0)) return true;
        }
    }
    return false;
}

int main() {
    int i;

    scanf("%d%d",&n,&m);
    for (i=0;i<m;i++) {
        int a, b;
        scanf("%d%d",&a,&b);
        lis[a].push_back(b);
    }
    memset(st,-1,sizeof(st));
    memset(ed,-1,sizeof(ed));
    for (i=1;i<=n;i++){
        if (st[i]<0) {
            if (dfs(i)) break;
        }
    }
    if (i==n+1) {
        printf("YES\n");
        return 0;
    }
    cyc.push_back(cyc.front());
    for (i=0;i+1<cyc.size();i++) {
        int t = cyc[i], s = cyc[i+1];
        for (int j=0;j<lis[t].size();j++) {
            if (lis[t][j]==s) {
                lis[t].erase(lis[t].begin()+j);
                break;
            }
        }

        if (!excyc()) {
            printf("YES\n");
            return 0;
        }
        lis[t].push_back(s);
    }
    printf("NO\n");

    return 0;
}