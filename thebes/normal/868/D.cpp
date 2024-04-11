#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

const int MN = 105, MM = 10;
struct wtf{vector<short> ok[MM+1];string pre, suf;}s[2*MN];
int n, m, i, j, k, l, c, x, y, f, mat; string t;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        cin >> t;
        for(j=0;j<min(MM,(int)t.size());j++)
            s[i].pre+=t[j];
        for(j=min(MM,(int)t.size())-1;j>=0;j--)
            s[i].suf+=t[t.size()-1-j];
        for(k=1;k<=MM;k++){
            for(j=0;j<(1<<k);j++){
                f=0;
                for(l=0;l<(int)t.size()-k+1;l++){
                    mat=0;
                    for(c=0;c<k;c++){
                        if(t[l+c]-'0'!=((1<<c)&j?1:0)){
                            mat=1;
                            break;
                        }
                    }
                    if(!mat){
                        f=1;
                        break;
                    }
                }
                s[i].ok[k].pb(f);
            }
        }
    }
    for(scanf("%d",&m),i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        t.clear();
        t+=s[x].suf;
        t+=s[y].pre;
        for(k=1;k<=MM;k++){
            for(j=0;j<(1<<k);j++){
                if(s[x].ok[k][j]||s[y].ok[k][j]){
                    s[n+i].ok[k].pb(1);
                    continue;
                }
                else s[n+i].ok[k].pb(0);
                f=0;
                for(l=0;l<(int)t.size()-k+1;l++){
                    mat=0;
                    for(c=0;c<k;c++){
                        if(t[l+c]-'0'!=((1<<c)&j?1:0)){
                            mat=1;
                            break;
                        }
                    }
                    if(!mat){
                        f=1;
                        break;
                    }
                }
                if(f) s[n+i].ok[k][j]=f;
            }
        }
        t.clear();
        t+=s[x].pre; t+=s[y].pre;
        for(j=0;j<min(MM,(int)t.size());j++)
            s[n+i].pre+=t[j];
        t.clear();
        t+=s[x].suf; t+=s[y].suf;
        for(j=min(MM,(int)t.size())-1;j>=0;j--)
            s[n+i].suf+=t[t.size()-1-j];
        int fnd = 0;
        for(k=1;k<=MM;k++){
            int rip = 0;
            for(auto v : s[n+i].ok[k]){
                if(!v){
                    rip=1;
                    break;
                }
            }
            if(rip){
                printf("%d\n",k-1);
                fnd=1; break;
            }
        }
        if(!fnd) printf("%d\n",MM);
    }
    return 0;
}