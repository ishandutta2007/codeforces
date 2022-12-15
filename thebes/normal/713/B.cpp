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

const int MN = 1<<17;
int n, sx, sy, ex, ey, lo, hi;

inline int qu(int x,int y,int a,int b){
    printf("? %d %d %d %d\n",x,y,a,b);
    fflush(stdout);
    int r; scanf("%d",&r); return r;
}

inline int qur(pii x,pii y){
    return qu(x.first,y.first,x.second,y.second);
}

int main(){
    scanf("%d",&n);
    sx=sy=1; ex=ey=n;
    lo=2,hi=n+1;
    while(lo<hi){
        int m=(lo+hi)>>1;
        if(qu(m,sy,ex,ey)==2) lo=m+1;
        else hi=m;
    }
    sx=lo-1;
    lo=sx,hi=n;
    while(lo<hi){
        int m=(lo+hi)>>1;
        if(qu(sx,sy,m,ey)==2) hi=m;
        else lo=m+1;
    }
    ex=lo;
    lo=2,hi=n+1;
    while(lo<hi){
        int m=(lo+hi)>>1;
        if(qu(sx,m,ex,ey)==2) lo=m+1;
        else hi=m;
    }
    sy=lo-1;
    lo=sy,hi=n;
    while(lo<hi){
        int m=(lo+hi)>>1;
        if(qu(sx,sy,ex,m)==2) hi=m;
        else lo=m+1;
    }
    ey=lo;
    lo=sx,hi=ex;
    while(lo<hi){
        int m=(lo+hi)>>1;
        if(qu(sx,sy,m,ey)==1) hi=m;
        else lo=m+1;
    }
    pii a(sx,lo), b(lo+1,ex);
    lo=sy,hi=ey;
    while(lo<hi){
        int m=(lo+hi)>>1;
        if(qu(sx,sy,ex,m)==1) hi=m;
        else lo=m+1;
    }
    pii c(sy,lo), d(lo+1,ey);
    if(b.first>b.second||qu(b.first,sy,b.second,ey)==0){
        lo=d.first+1, hi=d.second+1;
        while(lo<hi){
            int m=(lo+hi)>>1;
            if(qu(sx,m,ex,ey)==1) lo=m+1;
            else hi=m;
        }
        d.first=lo-1;
        lo=sx+1,hi=ex+1;
        while(lo<hi){
            int m=(lo+hi)>>1;
            if(qu(m,sy,ex,ey)==1) lo=m+1;
            else hi=m;
        }
        b.first=lo-1;
        if(a.second==ex){
            if(!qur(a,c)) swap(c,d);
        }
        else{
            if((qur(a,c)&&qur(b,d))) lo=0;
            else if(qur(a,d)&&qur(b,c)) swap(c,d);
            else{
                swap(a.second,b.second);
                if(qur(a,d)&&qur(b,c)) swap(c,d);
            }
        }
    }
    else{
        lo=b.first+1, hi=b.second+1;
        while(lo<hi){
            int m=(lo+hi)>>1;
            if(qu(m,sy,ex,ey)==1) lo=m+1;
            else hi=m;
        }
        b.first=lo-1;
        lo=sy+1,hi=ey+1;
        while(lo<hi){
            int m=(lo+hi)>>1;
            if(qu(sx,m,ex,ey)==1) lo=m+1;
            else hi=m;
        }
        d.first=lo-1;
        if(c.second==ex){
            if(!qur(a,c)) swap(c,d);
        }
        else{
            if(qur(a,c)&&qur(b,d)) lo=0;
            else if(qur(a,d)&&qur(b,c)) swap(c,d);
            else{
                swap(c.second,d.second);
                if(qur(a,d)&&qur(b,c)) swap(c,d);
            }
        }
    }
    printf("! %d %d %d %d %d %d %d %d\n",a.first,c.first,a.second,c.second,b.first,d.first,b.second,d.second);
    fflush(stdout);
    return 0;
}