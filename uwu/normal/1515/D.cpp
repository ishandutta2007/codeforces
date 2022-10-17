#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, nl, nr; cin >> n >> nl >> nr;
        map<int,int> l, r;
        for (int i=1;i<=nl;++i){
            int a; cin >> a;
            l[a]++;
        }
        for (int i=1;i<=nr;++i){
            int a; cin >> a;
            r[a]++;
        }
        int ans=0;
        for (int i=1;i<=n;++i){
            if (l.count(i)&&r.count(i)){
                int mn=min(l[i],r[i]);
                l[i]-=mn, r[i]-=mn;
            }
        }
        int totl=0, totr=0;
        for (int i=1;i<=n;++i){
            totl+=l[i];
            totr+=r[i];
            if (l[i]==0) l.erase(i);
            if (r[i]==0) r.erase(i);
        }
        if (totr>totl) swap(l,r), swap(totr,totl);
        ans+=totr;
        int a=0, b=0;
        for (int i=1;i<=n;++i){
            if (!l.count(i)) continue;
            a+=l[i]/2, b+=l[i]%2;
        }
        int sub=min(b,totr);
        b-=sub, totr-=sub;
        totr/=2;
        a-=totr;
        ans+=a+b;
        cout << ans << '\n';
    }
}