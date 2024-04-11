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

const ll MN = 205;
ll N, L, i, j, k, arr[MN], nxt=1, hsh[MN][MN], pw[MN]={1}, ree[MN][MN];
ll mat[MN][MN], b[MN][MN], op[MN][MN];
string s[MN]; vl id[MN];

ll gethsh(ll id,ll x,ll y){return hsh[id][y]-hsh[id][x-1]*pw[y-x+1];}

inline void mul(bool dbl=1){
    for(i=1;i<=nxt;i++){for(j=1;j<=nxt;j++)b[i][j]=-1LL<<60;}
    for(i=1;i<=nxt;i++){
        for(j=1;j<=nxt;j++){
            for(k=1;k<=nxt;k++){
                if(dbl) b[i][j]=max(b[i][j],mat[i][k]+mat[k][j]);
                else b[i][j]=max(b[i][j],mat[i][k]+op[k][j]);
            }
        }
    }
    for(i=1;i<=nxt;i++){for(j=1;j<=nxt;j++)mat[i][j]=b[i][j];}
}

int main(){
    for(scanf("%lld%lld",&N,&L),i=1;i<=N;i++)
        scanf("%lld",&arr[i]);
    for(i=1;i<=N;i++){
        cin >> s[i];
        for(j=0;j<s[i].size();j++){
            hsh[i][j+1]=hsh[i][j]*133LL+s[i][j]-'a'+1;
            id[i].pb(++nxt);
        }
    }
    for(i=1;i<MN;i++)
        pw[i]=133LL*pw[i-1];
    for(i=1;i<=nxt;i++){
        for(j=1;j<=nxt;j++){
            op[i][j]=-1LL<<60;
        }
    }
    for(i=1;i<=N;i++){
        for(j=0;j<s[i].size();j++){
            ll bonus=0;
            for(k=1;k<=N;k++){
                if(s[k].size()<=j+1&&gethsh(k,1,s[k].size())==gethsh(i,j+2-s[k].size(),j+1))
                    bonus+=arr[k];
            }
            if(!j) op[1][id[i][j]]=bonus;
            else op[id[i][j-1]][id[i][j]]=bonus;
            ree[i][j]=bonus;
        }
        for(k=1;k<=N;k++){
            for(j=1;j<min(s[i].size(),s[k].size());j++){
                if(gethsh(i,1,j)==gethsh(k,s[k].size()-j+1,s[k].size()))
                    op[id[k].back()][id[i][j]]=ree[i][j];
            }
        }
    }
    for(j=1;j<=nxt;j++){
        op[j][1]=0;
        for(i=1;i<=N;i++)
            op[j][id[i][0]]=ree[i][0];
    }
    vl bit;
    while(L){
        bit.insert(bit.begin(),L&1);
        L>>=1;
    }
    bit.erase(bit.begin());
    for(i=1;i<=nxt;i++){
        for(j=1;j<=nxt;j++)
            mat[i][j]=op[i][j];
    }
    for(auto v : bit){
        mul();
        if(v) mul(0);
    }
    ll ans=0;
    for(i=1;i<=nxt;i++){
        ans=max(ans,mat[1][i]);
    }
    printf("%lld\n",ans);
    return 0;
}