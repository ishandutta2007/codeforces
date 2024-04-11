#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1001;

vector<int> graph[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,x; cin >> n >> x;
        for (int i=1;i<=n;++i){ graph[i].clear(); }
        for (int i=1,a,b;i<n;++i){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        if (graph[x].size()==1||graph[x].size()==0){ cout << "Ayush" << '\n'; continue; }
        if ((n-3)%2==1) cout << "Ayush" << '\n';
        else cout << "Ashish" << '\n';
    }
}