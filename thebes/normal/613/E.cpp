#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

namespace output{
    void __(short x){cout<<x;}
    void __(unsigned x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class S,class T>
    void __(const pair<S,T>&x){__(DEBUG?"(":""),__(x.first),__(DEBUG?", ":" "),__(x.second),__(DEBUG?")":"");}
    template<class T>
    void __(const vector<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const set<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const multiset<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class S,class T>
    void __(const map<S,T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    void pr(){cout<<"\n";}
    template<class S,class... T>
    void pr(const S&a,const T&...b){__(a);if(sizeof...(b))__(' ');pr(b...);}
}

using namespace output;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,char> pic;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MN = 2020, mod = 1e9+7;
int dpr[MN][2][MN], dpl[MN][2][MN], dps[MN][2][MN], c[MN][2][MN], n, m, i, j, k, len, res, hsh[MN][2], rhsh[MN][2], th[MN], pw[MN]={1}, ans;
string s[2], t;
inline int get(int x,int y,int k){
    res=(hsh[y][k]-1LL*hsh[x-1][k]*pw[y-x+1])%mod;
    while(res<0) res+=mod;
    return res;
}
inline int rget(int x,int y,int k){
    res=(rhsh[x][k]-1LL*rhsh[y+1][k]*pw[y-x+1])%mod;
    while(res<0) res+=mod;
    return res;
}
inline int tget(int x,int y){
    res=(th[y]-1LL*th[x-1]*pw[y-x+1])%mod;
    while(res<0) res+=mod;
    return res;
}

int main(){
    cin >> s[0] >> s[1] >> t;
    n = s[0].size(), m = t.size();
    s[0].insert(s[0].begin(),' ');
    s[1].insert(s[1].begin(),' ');
    t.insert(t.begin(),' ');
    for(i=1;i<=n;i++){
        pw[i]=pw[i-1]*133LL%mod;
        for(k=0;k<2;k++)
            hsh[i][k]=(hsh[i-1][k]*133LL+s[k][i]-'a'+1)%mod;
    }
    for(i=n;i>=1;i--){
        for(k=0;k<2;k++)
            rhsh[i][k]=(rhsh[i+1][k]*133LL+s[k][i]-'a'+1)%mod;
    }
    for(i=1;i<=m;i++)
        th[i]=(th[i-1]*133LL+t[i]-'a'+1)%mod;
    for(i=n;i>=1;i--){
        for(k=0;k<2;k++){
            for(j=1;j<=m;j++){
                if(s[k][i]==t[j]){
                    if(j==m) dpr[i][k][j]=1;
                    else dpr[i][k][j]=dpr[i+1][k][j+1];
                }
            }
        }
        for(k=0;k<2;k++){
            for(j=1;j<=m;j++){
                if(s[k][i]==t[j]&&j<m)
                    dps[i][k][j]=dpr[i][!k][j+1];
            }
        }
        for(k=0;k<2;k++){
            for(j=1;j<=m;j++){
                if(s[k][i]==t[j]){
                    dpr[i][k][j]+=dps[i][k][j];
                    dps[i][k][j]=0;
                    if((m-j+1)%2==0&&m-j+1>=4){
                        len=m-j+1;
                        if(i+len/2-1<=n&&get(i,i+len/2-1,k)==tget(j,j+len/2-1)&&rget(i,i+len/2-1,!k)==tget(j+len/2,m))
                            dpr[i][k][j]++;
                    }
                    if(dpr[i][k][j]>=mod) dpr[i][k][j]-=mod;
                }
            }
        }
        for(k=0;k<2;k++)
            ans=(ans+dpr[i][k][1])%mod;
        for(k=0;k<2;k++){
            for(j=2;2*j<m;j++){
                if(i+j-1<=n&&get(i,i+j-1,k)==tget(1,j)&&rget(i,i+j-1,!k)==tget(j+1,2*j))
                    c[i-1][!k][2*j+1]++;
            }
        }
    }
    for(i=1;i<=n;i++){
        for(k=0;k<2;k++){
            for(j=1;j<=m;j++){
                if(s[k][i]==t[j]){
                    if(j==m&&m!=1) dpl[i][k][j]=1;
                    else dpl[i][k][j]=dpl[i-1][k][j+1];
                }
            }
        }
        for(k=0;k<2;k++){
            for(j=1;j<=m;j++){
                if(s[k][i]==t[j]&&j<m&&m!=2)
                    dps[i][k][j]=dpl[i][!k][j+1];
                else dps[i][k][j]=0;
            }
        }
        for(k=0;k<2;k++){
            for(j=1;j<=m;j++){
                if(s[k][i]==t[j]){
                    dpl[i][k][j]+=dps[i][k][j];
                    dps[i][k][j]=0;
                    if((m-j+1)%2==0&&m-j+1>=4){
                        len=m-j+1;
                        if(i-len/2+1>=1&&rget(i-len/2+1,i,k)==tget(j,j+len/2-1)&&get(i-len/2+1,i,!k)==tget(j+len/2,m))
                            dpl[i][k][j]++;
                    }
                    if(dpl[i][k][j]>=mod) dpl[i][k][j]-=mod;
                }
            }
        }
        for(k=0;k<2;k++)
            ans=(ans+dpl[i][k][1])%mod;
        for(k=0;k<2;k++){
            for(j=2;2*j<m;j++){
                if(i-j+1>=1&&rget(i-j+1,i,k)==tget(1,j)&&get(i-j+1,i,!k)==tget(j+1,2*j))
                    ans=(ans+dpr[i+1][!k][2*j+1])%mod;
            }
        }
        for(k=0;k<2;k++){
            for(j=1;j<=m;j++)
                ans=(ans+1LL*dpl[i][k][j]*c[i][k][j])%mod;
        }
    }
    printf("%d\n",ans);
    return 0;
}