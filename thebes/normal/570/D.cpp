#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int MN = 5e5+5;
int N, M, i, x, y, c[MN][26], vis[MN][2], nxt;
map<int,int> id[MN];
string s;
vi adj[MN];

void dfs(int n,int d){
    vis[n][0] = ++nxt;
    int pre = 0;
    if(!id[d].empty()) pre=(--id[d].end())->second;
    id[d][vis[n][0]]=n;
    for(int i=0;i<26;i++) c[n][i]=c[pre][i];
    c[n][s[n-1]-'a']++;
    for(auto v : adj[n]) dfs(v, d+1);
    vis[n][1] = nxt;
}

int main(){
    for(scanf("%d%d",&N,&M),i=2;i<=N;i++){
        scanf("%d",&x);
        adj[x].push_back(i);
    }
    cin >> s;
    dfs(1,1);
    for(;M;M--){
        scanf("%d%d",&x,&y);
        if(id[y].empty()){printf("Yes\n"); continue;}
        int s=-1, e=-1;
        auto it = id[y].upper_bound(vis[x][1]); it--;
        if(it!=id[y].end()) e=it->second;
        it = id[y].lower_bound(vis[x][0]);
        if(it==id[y].begin()) s=-1;
        else s=(--it)->second;
        int f=0;
        if(e==-1) printf("Yes\n");
        else if(s==-1){
            for(i=0;i<26;i++){
                if(c[e][i]&1) f++;
            }
            if(f>1) printf("No\n");
            else printf("Yes\n");
        }
        else{
            for(i=0;i<26;i++){
                if((c[e][i]-c[s][i])&1) f++;
            }
            if(f>1) printf("No\n");
            else printf("Yes\n");
        }
    }
    return 0;
}