#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

ll a[1005][1005];
ll c[1005];
int ans[1005];
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ii ji cin>>a[i][j];
    memset(ans,0x3f,sizeof(ans));
    ll g=0;
    ii g=gcd(g,a[1][i]);
    for(ll i=1;i*i<=g;++i) {
        if(g%i==0) {
            int ok = 1;
            c[1] = i;
            for(int k=2;k<=n;++k) c[k]=a[1][k]/c[1];
            for(int i1=1;i1<=n;++i1) {
                if(!ok) break;
                for(int j1=1;j1<=n;++j1) {
                    if(i1!=j1 && a[i1][j1] != c[i1] * c[j1]) {
                        ok = 0;
                        break;
                    }
                }
            }
            if(ok) {
                ii cout<<c[i]<<" ";cout<<endl;
                return 0;
            }
            ok = 1;
            c[1] = g/i;
            for(int k=2;k<=n;++k) c[k]=a[1][k]/c[1];
            for(int i1=1;i1<=n;++i1) {
                if(!ok) break;
                for(int j1=1;j1<=n;++j1) {
                    if(i1!=j1 && a[i1][j1] != c[i1] * c[j1]) {
                        ok = 0;
                        break;
                    }
                }
            }
            if(ok) {
                ii cout<<c[i]<<" ";cout<<endl;
                return 0;
            }
        }
    }
}