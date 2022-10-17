#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

struct Edge{ bool dir; int a,b; };
int arr[MAXN],in[MAXN];
vector<int> graph[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,m; cin >> n >> m;
        vector<Edge> edges;
        for (int i=1;i<=n;++i) graph[i].clear(), in[i]=0;
        for (int i=1,a,b,c;i<=m;++i){
            cin >> a >> b >> c;
            edges.push_back({a,b,c});
            if (a) graph[b].push_back(c), in[c]++;
        }   
        int cnt=0; queue<int> q;
        // for (int i=1;i<=n;++i) cout << in[i] << " ";
        // cout << '\n';
        for (int i=1;i<=n;++i){ if (in[i]==0) q.push(i); }
        while (!q.empty()){
            int curr=q.front(); q.pop();
            arr[curr]=++cnt;
            for (int x:graph[curr]){
                in[x]--;
                if (in[x]==0) q.push(x);
            }
        }
        
        if (cnt!=n) cout << "NO" << '\n';
        else{
            cout << "YES" << '\n';
            for (Edge x:edges){
                if (!x.dir&&arr[x.b]<arr[x.a]){
                    swap(x.a,x.b);
                }
                cout << x.a << " " << x.b << '\n';
            }
        }
    }
}