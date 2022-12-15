#include <bits/stdc++.h>
using namespace std;

namespace debug{
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
    template<class P1,class P2>
    void __(const pair<P1,P2>&x){__("("),__(x.first),__(", "),__(x.second),__(")");}
    template<class T>
    void __(const vector<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    template<class T>
    void __(const set<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    template<class T,class T2>
    void __(const map<T,T2>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(make_pair(v.first,v.second)),_ffs=1;__("}");}
    void screm(){__("\n");}
    template<class T1,class... T2>
    void screm(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" | "),screm(t2...);else __("\n");}
    void pr(){__("\n");}
    template<class T1,class... T2>
    void pr(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" "),pr(t2...);else __("\n");}

}

using namespace debug;

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
#define foxr(i,x,y) for(int i=(x);i>=(y);i--)

const int MN = 66;
int t, n, m, i, j, x, y, a[MN][MN], ans, flg;

int main(){
    scanf("%d",&t);
    fox(q,1,t){
        scanf("%d%d",&n,&m); flg=0;
        fox(i,1,n){
            getchar();
            fox(j,1,m){
                a[i][j]=getchar()=='A';
                if(!a[i][j]) flg=1;
            }
        }
        ans = 1<<30;
        if(!flg) printf("0\n");
        else{
            flg = 0;
            fox(i,1,n){
                fox(j,1,m){
                    if(a[i][j]) flg=1;
                }
            }
            if(!flg) printf("MORTAL\n");
            else{
                int ok = 0; flg = 0;
                fox(i,1,n) if(!a[i][1]) flg=1;
                if(!flg) ok = 1;
                flg = 0;
                fox(i,1,n) if(!a[i][m]) flg=1;
                if(!flg) ok = 1;
                flg = 0;
                fox(i,1,m) if(!a[1][i]) flg=1;
                if(!flg) ok = 1;
                flg = 0;
                fox(i,1,m) if(!a[n][i]) flg=1;
                if(!flg) ok = 1;
                if(ok) printf("1\n");
                else{
                    if(a[1][1]||a[1][m]||a[n][1]||a[n][m]) printf("2\n");
                    else{
                        int fnd=0;
                        fox(i,1,n){
                            flg = 0;
                            fox(j,1,m) if(!a[i][j]) flg=1;
                            if(!flg) fnd=1;
                        }
                        fox(i,1,m){
                            flg = 0;
                            fox(j,1,n) if(!a[j][i]) flg=1;
                            if(!flg) fnd=1;
                        }
                        if(fnd) printf("2\n");
                        else{
                            fox(i,1,n){
                                if(a[i][1]||a[i][m]) ok=1;
                            }
                            fox(i,1,m){
                                if(a[1][i]||a[n][i]) ok=1;
                            }
                            if(ok) printf("3\n");
                            else printf("4\n");
                        }
                    }
                }
            }
        }
    }
    return 0;
}