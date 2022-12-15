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
#define F first
#define S second

const int MN = 2e4+5;
const double eps = 1e-7, PI = (double)acos((double)-1);
int N, D, i, j, x, y, r;
double ang, lo, hi, mid;
inline double dis(pii x){
    return sqrt(1LL*x.F*x.F+1LL*x.S*x.S);
}
inline double dis(pdd x){
    return sqrt(x.F*x.F+x.S*x.S);
}
pdd vec;
vector<pair<double,int>> go;

int main(){
    scanf("%d%d",&N,&D);
    for(i=1;i<=N;i++){
        scanf("%d%d%d",&x,&y,&r);
        double dd = dis(make_pair(x,y));
        int approx = dd/(double)D;
        ang = atan2(y,x);
        //pr(">",ang);
        for(j=approx;j>0;j--){
            if(D*j+eps>=dd-r){
                lo=ang-PI/2, hi=ang;
                while(lo+eps<hi){
                    mid=(lo+hi)/2;
                    vec={D*j*cos(mid),D*j*sin(mid)};
                    if(dis(make_pair(vec.F-x,vec.S-y))<=r) hi=mid;
                    else lo=mid+eps;
                }
                double a = lo;
                if(a<0) a += 2*PI;
                if(a>=2*PI) a -= 2*PI;
                lo=ang+eps, hi=ang+eps+PI/2;
                while(lo+eps<hi){
                    mid=(lo+hi)/2;
                    vec={D*j*cos(mid),D*j*sin(mid)};
                    if(dis(make_pair(vec.F-x,vec.S-y))<=r) lo=mid+eps;
                    else hi=mid;
                }
                double b = lo;
                if(b<0) b += 2*PI;
                if(b>=2*PI) b -= 2*PI;
                if(a<b){
                    go.pb({a,1});
                    go.pb({b,0});
                }
                else{
                    go.pb({a,1});
                    go.pb({0,1});
                    go.pb({b,0});
                }
                //pr(">",j,a,b);
            }
            else break;
        }
        for(j=approx+1;;j++){
            if(D*j-eps<=dd+r){
                lo=ang-PI/2, hi=ang;
                while(lo+eps<hi){
                    mid=(lo+hi)/2;
                    vec={D*j*cos(mid),D*j*sin(mid)};
                    if(dis(make_pair(vec.F-x,vec.S-y))<=r) hi=mid;
                    else lo=mid+eps;
                }
                double a = lo;
                if(a<0) a += 2*PI;
                if(a>=2*PI) a -= 2*PI;
                lo=ang+eps, hi=ang+eps+PI/2;
                while(lo+eps<hi){
                    mid=(lo+hi)/2;
                    vec={D*j*cos(mid),D*j*sin(mid)};
                    if(dis(make_pair(vec.F-x,vec.S-y))<=r) lo=mid+eps;
                    else hi=mid;
                }
                double b = lo;
                if(b<0) b += 2*PI;
                if(b>=2*PI) b -= 2*PI;
                if(a<b){
                    go.pb({a,1});
                    go.pb({b,0});
                }
                else{
                    go.pb({a,1});
                    go.pb({0,1});
                    go.pb({b,0});
                }
                //pr(">",j,a,b);
            }
            else break;
        }
    }
    sort(go.begin(),go.end(),[](pair<double,int>i,pair<double,int>j){return i.F<j.F;});
    //pr(">",go);
    int ans = 0, cur = 0;
    for(i=0;i<(int)go.size();i=j){
        for(j=i;j<(int)go.size()&&go[j].F==go[i].F;j++){
            if(go[j].S) cur++;
            else cur--;
        }
        ans = max(ans, cur);
    }
    printf("%d\n",ans);
    return 0;
}