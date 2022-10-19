#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

vector<ll> l,r;

int main(){
    ///cin.tie(0)->sync_with_stdio(0);
    int n, d, m; cin >> n >> d >> m;
    for (int i=1,a;i<=n;++i){
        cin >> a;
        if (a<=m) l.push_back(a);
        else r.push_back(a);
    }
    l.push_back(0x3f3f3f3f); r.push_back(0x3f3f3f3f);
    sort(l.begin(),l.end(),greater<int>()); sort(r.begin(),r.end(),greater<int>());
    l[0]=r[0]=0;
    for (int i=1;i<l.size();++i) l[i]+=l[i-1];
    for (int i=1;i<r.size();++i) r[i]+=r[i-1];
    for (int i=1;i<=n;++i) r.push_back(r.back());
    ll ans=0;
    for (int i=l.size()-1;i>=0;--i){
        //cout << ((n-i+d)/(d+1)) << '\n';
        ans=max(ans,l[i]+r[((n-i+d)/(d+1))]);
    }
    cout << ans << '\n';
}