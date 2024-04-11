#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;

const int maxn = 100050;
int a[maxn];
int main() {
    int n;
    cin>>n;
    if(n<=2) return cout<<0<<endl,0;
    ii cin>>a[i];
    int ans=1e9;
    for(int x=-1;x<=1;x++) {
        for(int y=-1;y<=1;++y) {
            int tmp=abs(x)+abs(y);
            int a1=a[1]+x,a2=a[2]+y,d=a2-a1,aa=a2,ok=1;
            for(int i=3;i<=n;++i) {
                aa+=d;
                if(abs(aa-a[i])>1) {
                    ok=0;
                    break;
                }
                tmp+=abs(aa-a[i]);
            }
            if(!ok) continue;
            ans=min(ans,tmp);
        }
    }
    if(ans==1e9)cout<<-1<<endl;
    else cout<<ans<<endl;
}