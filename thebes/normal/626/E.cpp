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
#define F first
#define S second


const int MN = 2e5+5;
int N, i, arr[MN], lo, hi, huh; ll ps[MN];
long double ans; vi sna; pii go;

int main(){
    for(scanf("%d",&N),i=1;i<=N;i++)
        scanf("%d",&arr[i]);
    sort(arr+1,arr+N+1);
    for(i=1;i<=N;i++)
        ps[i]=ps[i-1]+arr[i];
    ans=-1;
    for(i=1;i<=N;i++){
        lo=0, hi=min(i-1,N-i);
        while(lo<hi){
            int m=(lo+hi)>>1;
            ld a=(ps[N]-ps[N-m]+ps[i]-ps[i-m-1])/(ld)(2*m+1);
            ld b=(ps[N]-ps[N-m-1]+ps[i]-ps[i-m-2])/(ld)(2*m+3);
            if(b-a<=0) hi=m;
            else lo=m+1;
        }
        ld res=(ps[N]-ps[N-lo]+ps[i]-ps[i-lo-1])/(ld)(2*lo+1)-arr[i];
        if(res>ans) ans=res, go={i,lo}, huh=0;
        if(lo+1<=N){
            lo=0, hi=min(i-1,N-i-1);
            while(lo<hi){
                int m=(lo+hi)>>1;
                ld a=(ps[N]-ps[N-m]+ps[i+1]-ps[i-m-1])/(ld)(2*m+2);
                ld b=(ps[N]-ps[N-m-1]+ps[i+1]-ps[i-m-2])/(ld)(2*m+4);
                if(b-a<=0) hi=m;
                else lo=m+1;
            }
            res=(ps[N]-ps[N-lo]+ps[i+1]-ps[i-lo-1])/(ld)(2*lo+2)-(arr[i]+arr[i+1])/(ld)2;
            if(res>ans) ans=res, go={i,lo}, huh=1;
        }
    }
    if(!huh){
        for(i=go.F-go.S;i<=go.F;i++)
            sna.pb(arr[i]);
        for(i=0;i<go.S;i++)
            sna.pb(arr[N-i]);
    }
    else{
        for(i=go.F-go.S;i<=go.F+1;i++)
            sna.pb(arr[i]);
        for(i=0;i<go.S;i++)
            sna.pb(arr[N-i]);
    }
    sort(sna.begin(),sna.end());
    printf("%d\n",(int)sna.size());
    for(auto v : sna)
        printf("%d ",v);
    printf("\n");
    return 0;
}