#include <bits/stdc++.h>
using namespace std;

namespace debug{
    void __(short x){cout<<x;}
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

const int MN = 2005;
int N, M, i, j, k, lo, hi, len, x, psa[MN][MN], ok;
string s[MN];

int main(){
    for(scanf("%d%d",&N,&M),i=1;i<=N;i++){
        cin >> s[i]; s[i].insert(s[i].begin(),' ');
        for(j=1;j<=M;j++){
            if(s[i][j]=='w') psa[i][j]=1;
            psa[i][j]+=psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1];
        }
    }
    lo = 1; hi = min(N,M);
    k = psa[N][M];
    while(lo<hi){
        int m = (lo+hi)/2;
        int fnd = 0;
        for(i=1;i<=N-m+1;i++){
            for(j=1;j<=M-m+1;j++){
                int r = psa[i+m-1][j+m-1]-psa[i-1][j+m-1]-psa[i+m-1][j-1]+psa[i-1][j-1];
                if(r==k) fnd=1,ok=1;
            }
        }
        if(fnd) hi=m;
        else lo=m+1;
    }
    int m = lo, fnd = 0;
    for(i=1;i<=N-m+1;i++){
        for(j=1;j<=M-m+1;j++){
            int r = psa[i+m-1][j+m-1]-psa[i-1][j+m-1]-psa[i+m-1][j-1]+psa[i-1][j-1];
            if(r==k) fnd=1,ok=1;
        }
    }
    if(!ok) printf("-1\n");
    else{
        int m = lo;
        for(i=1;i<=N-m+1;i++){
            for(j=1;j<=M-m+1;j++){
                int r = psa[i+m-1][j+m-1]-psa[i-1][j+m-1]-psa[i+m-1][j-1]+psa[i-1][j-1];
                int t = 0;
                if(m>2) t = psa[i+m-2][j+m-2]-psa[i][j+m-2]-psa[i+m-2][j]+psa[i][j];
                if(r-t==k){
                    for(int re=0;re<m;re++){
                        if(s[i][j+re]=='.') s[i][j+re]='+';
                        if(s[i+re][j]=='.') s[i+re][j]='+';
                        if(s[i+m-1][j+re]=='.') s[i+m-1][j+re]='+';
                        if(s[i+re][j+m-1]=='.') s[i+re][j+m-1]='+';
                    }
                    for(i=1;i<=N;i++){
                        for(j=1;j<=M;j++) putchar(s[i][j]);
                        printf("\n");
                    }
                    return 0;
                }
            }
        }
        printf("-1\n");
    }
    return 0;
}