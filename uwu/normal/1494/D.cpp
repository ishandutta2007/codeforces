#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int a[501][501];
int p[MAXN], val[MAXN], cnt, n;

void solve(set<int> &s, int par){
    if (s.empty()) return;
    int v=*s.begin(); s.erase(v);
    val[v]=a[v][v];
    if (s.empty()) return void(p[v]=par);
    vector<int> vec={val[v],val[par]};
    map<int,int> m={{val[par],par}};
    for (int i=1;i<=n;++i) if (s.count(i)) vec.push_back(a[v][i]);
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for (int i=1;i<vec.size()-1;++i) val[cnt]=vec[i], m[vec[i]]=cnt++;
    for (int i=1;i<vec.size()-1;++i) p[m[vec[i]]]=m[vec[i+1]];
    p[v]=m[vec[1]];
    vector<set<int>> nxt(vec.size());
    for (int i=1;i<=n;++i){
        if (s.count(i)) nxt[lower_bound(vec.begin(),vec.end(),a[v][i])-vec.begin()].insert(i);
    }
    for (int i=1;i<nxt.size();++i) solve(nxt[i],m[vec[i]]); 
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n; cnt=n+1;
    for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) cin >> a[i][j];
    val[0]=inf;
    set<int> s;
    for (int i=1;i<=n;++i) s.insert(i);
    solve(s,0);
    int src;
    for (int i=1;i<cnt;++i) if (p[i]==0) src=i;
    cout << cnt-1 << '\n';
    for (int i=1;i<cnt;++i) cout << val[i] << " ";
    cout << '\n';
    cout << src << '\n';
    for (int i=1;i<cnt;++i) if (p[i]) cout << i << " " << p[i] << '\n';
}