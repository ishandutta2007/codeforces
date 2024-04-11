#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back

int a[1005],b[1005],c[1005];
int main() {
    int n;
    cin>>n;
    ii cin>>a[i],c[i]=b[i]=a[i];
    sort(al(b));
    vii ans;
    int ok = 1;
    for(int i=n;i>=1;--i) {
        vii tmp;
        for(int j=1;j<i;++j) if(c[j] > c[i]) tmp.pb({c[j], j});
        sort(all(tmp));
        for(auto p : tmp) {
            int x = p.second;
            ans.pb({x, i});
            swap(a[x], a[i]);
        }
        if(!ok) break;
    }
    for(int i=2;i<=n;++i) if(a[i]<a[i-1]) ok=0;
//    ii cout<<a[i]<<" ";cout<<endl;
    if(ok) {
        cout<<ans.size()<<endl;
        for(auto p : ans) cout<<p.first<<" "<<p.second<<endl;
    } else cout<<-1<<endl;

}