#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
map<int,int> pos[200001];
int deg[200001];
vector<pair<int,int>> adj[200001];
vector<int> rev[200001];
bool x[9][9][9][9];
int n,m,k;
vector<string> test;
void generate(string s) {
    if(s.length()==k) {
        test.push_back(s);
        return;
    }
    for(int i=0;i<=s.length();i++) {
        generate(s+to_string(i));
    }
}
int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        --u, --v;
        adj[u].push_back({w,v});
        rev[v].push_back(u);
        ++deg[u];
    }
    for(int i=0;i<n;i++) if(deg[i]>=1) --deg[i];
    for(int i=0;i<n;i++) {
        sort(adj[i].begin(),adj[i].end());
        for(int j=0;j<adj[i].size();j++) {
            pos[i][adj[i][j].s] = j;
            //cout << i << " " << adj[i][j].s << endl;
        }
    }
    for(int i=0;i<n;i++) {
        int in[k][k];
        for(int a=0;a<k;a++)
            for(int b=0;b<k;b++) in[a][b] = 0;
        for(int j=0;j<rev[i].size();j++) {
            int a = rev[i][j];
            ++in[deg[a]][pos[a][i]];
        }
        vector<pair<int,int>> v;
        for(int a=0;a<k;a++) {
            for(int b=0;b<k;b++) {
                if(in[a][b]) {
                    v.push_back({a,b});
                    if(in[a][b]>=2) v.push_back({a,b});
                }
            }
        }
        for(int a=0;a<v.size();a++)
            for(int b=a+1;b<v.size();b++) {
                x[v[a].f][v[a].s][v[b].f][v[b].s] = 1;
                x[v[b].f][v[b].s][v[a].f][v[a].s] = 1;
            }
    }
    generate("");
    int ans = 0;
    for(auto &it : test) {
        bool work = true;
        for(int i=0;i<k && work;i++) {
            for(int j=i;j<k && work;j++) {
                if(x[i][it[i]-'0'][j][it[j]-'0']) work = false;
            }
        }
        if(work) ++ans;
    }
    cout << ans << endl;
}