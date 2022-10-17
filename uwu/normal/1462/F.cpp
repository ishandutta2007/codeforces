#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

struct bit{
    int a[2*MAXN];
    void ins(int i, int val=1){ for (;i<2*MAXN;i+=i&-i) a[i]+=val; }
    int get(int i){
        int ret=0;
        for (;i>0;i-=i&-i) ret+=a[i];
        return ret;
    }
    void clear(){ ms(a,0); }
} in, out;
int l[MAXN], r[MAXN];
vector<int> vals;
map<int,int> m;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vals.clear(); m.clear();
        for (int i=1;i<=n;++i) cin >> l[i] >> r[i], vals.push_back(l[i]), vals.push_back(r[i]);
        sort(vals.begin(),vals.end());
        for (int i=0;i<2*n;++i) m[vals[i]]=i+1;
        int ans=n;
        for (int i=1;i<=n;++i) in.ins(m[l[i]]), out.ins(m[r[i]]);
        for (int i=1;i<=n;++i){
            ans=min(ans,out.get(m[l[i]]-1)+n-in.get(m[r[i]]));
            // cout << out.get(m[l[i]]-1) << " " << n-in.get(m[r[i]]) << '\n';
        }
        cout << ans << '\n';
        for (int i=1;i<=n;++i) in.ins(m[l[i]],-1), out.ins(m[r[i]],-1);
    }
}