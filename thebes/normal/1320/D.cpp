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
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MN = 2e5+5, LG = 20, mod = 1e9+3;
int n, q, i, j, x, y, ln; ll hsh[MN][LG][2], c[MN][LG][2], lst[MN][LG][2], len[MN][LG][2], pw[MN]={1};
string t;

int main(){
    cin >> n >> t;
    t.insert(t.begin(),' ');
    for(i=1;i<=n;i++){
        pw[i]=pw[i-1]*133LL%mod;
        hsh[i][0][0]=hsh[i][0][1]=0;
        if(t[i]=='1'){
            lst[i][0][0]=1;
        }
        else{
            hsh[i][0][0]=hsh[i][0][1]=1;
            len[i][0][0]=len[i][0][1]=1;
        }
    }
    for(j=1;j<LG;j++){
        for(i=1;i<=n;i++){
            if(i+(1<<j)-1>n) continue;
            int nxt = i+(1<<(j-1));
            for(int k=0;k<2;k++){
                int l = lst[i][j-1][k];
                if(l==1&&t[nxt]=='0'){
                    int tmp = (133LL*hsh[i][j-1][k]+2)%mod;
                    hsh[i][j][k]=(1LL*tmp*pw[len[nxt][j-1][0]]+hsh[nxt][j-1][0])%mod;
                    c[i][j][k] = c[i][j-1][k]+c[nxt][j-1][0];
                    len[i][j][k] = len[i][j-1][k]+1+len[nxt][j-1][0];
                    lst[i][j][k] = lst[nxt][j-1][0];
                }
                else if(l==1){
                    hsh[i][j][k]=(1LL*hsh[i][j-1][k]*pw[len[nxt][j-1][1]]+hsh[nxt][j-1][1])%mod;
                    c[i][j][k] = c[i][j-1][k]+c[nxt][j-1][1]+1;
                    len[i][j][k] = len[i][j-1][k]+len[nxt][j-1][1];
                    lst[i][j][k] = lst[nxt][j-1][1];
                }
                if(!l&&t[nxt]=='0'){
                    hsh[i][j][k]=(1LL*hsh[i][j-1][k]*pw[len[nxt][j-1][0]]+hsh[nxt][j-1][0])%mod;
                    c[i][j][k] = c[i][j-1][k]+c[nxt][j-1][0];
                    len[i][j][k] = len[i][j-1][k]+len[nxt][j-1][0];
                    lst[i][j][k] = lst[nxt][j-1][0];
                }
                else if(!l){
                    hsh[i][j][k]=(1LL*hsh[i][j-1][k]*pw[len[nxt][j-1][0]]+hsh[nxt][j-1][0])%mod;
                    c[i][j][k] = c[i][j-1][k]+c[nxt][j-1][0];
                    len[i][j][k] = len[i][j-1][k]+len[nxt][j-1][0];
                    lst[i][j][k] = lst[nxt][j-1][0];
                }
            }
        }
    }
    for(scanf("%d",&q);q;q--){
        scanf("%d%d%d",&x,&y,&ln);
        int h1=0, c1=0, l1=0, h2=0, c2=0, l2=0;
        for(int i=LG-1;i>=0;i--){
            if((1<<i)&ln){
                if(t[x]=='1'){
                    if(l1){
                        c1+=1+c[x][i][1];
                        l1=lst[x][i][1];
                        h1=(1LL*h1*pw[len[x][i][1]]+hsh[x][i][1])%mod;
                    }
                    else{
                        c1+=c[x][i][0];
                        l1=lst[x][i][0];
                        h1=(1LL*h1*pw[len[x][i][0]]+hsh[x][i][0])%mod;
                    }
                }
                else{
                    if(l1){
                        c1+=c[x][i][0];
                        l1=lst[x][i][0];
                        int m = (133LL*h1+2)%mod;
                        h1=(1LL*m*pw[len[x][i][0]]+hsh[x][i][0])%mod;
                    }
                    else{
                        c1+=c[x][i][0];
                        l1=lst[x][i][0];
                        h1=(1LL*h1*pw[len[x][i][0]]+hsh[x][i][0])%mod;
                    }
                }
                x += (1<<i);
                if(t[y]=='1'){
                    if(l2){
                        c2+=1+c[y][i][1];
                        l2=lst[y][i][1];
                        h2=(1LL*h2*pw[len[y][i][1]]+hsh[y][i][1])%mod;
                    }
                    else{
                        c2+=c[y][i][0];
                        l2=lst[y][i][0];
                        h2=(1LL*h2*pw[len[y][i][0]]+hsh[y][i][0])%mod;
                    }
                }
                else{
                    if(l2){
                        c2+=c[y][i][0];
                        l2=lst[y][i][0];
                        int m = (133LL*h2+2)%mod;
                        h2=(1LL*m*pw[len[y][i][0]]+hsh[y][i][0])%mod;
                    }
                    else{
                        c2+=c[y][i][0];
                        l2=lst[y][i][0];
                        h2=(1LL*h2*pw[len[y][i][0]]+hsh[y][i][0])%mod;
                    }
                }
                y += (1<<i);
            }
        }
        if(l1) h1=(133LL*h1+2)%mod;
        if(l2) h2=(133LL*h2+2)%mod;
        if(c1==c2&&h1==h2) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}