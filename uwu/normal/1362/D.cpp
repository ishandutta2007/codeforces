#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=5e5+1;

vector<int> graph[MAXN];
int t[MAXN];
int val[MAXN];

bool cmp(int a, int b){ return t[a]<t[b]; }

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,m; cin >> n >> m;
    for (int i=0,a,b;i<m;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> arr;
    for (int i=1;i<=n;++i) cin >> t[i],arr.push_back(i);
    sort(arr.begin(),arr.end(),cmp);
    for (int x:arr){
        if (val[x]!=t[x]-1){ cout << -1 << '\n'; return 0; }
        for (int uwu:graph[x]){
            if (val[uwu]==t[x]-1) val[uwu]=t[x];
        }
    }
    for (int x:arr) cout << x << " ";
    cout << '\n';
}