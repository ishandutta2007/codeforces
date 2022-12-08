#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;
 
typedef long long ll;
 
template<typename T>
class MonotoneCHT{
private:
    struct line{
        T a,b;
        line(T a,T b):a(a),b(b){}
        bool operator<(const line& r)const{
            return (a!=r.a? a<r.a:b<r.b);
        }
        bool operator>(const line& r)const{
            return (a!=r.a? a>r.a:b>r.b);
        } 
    };
    //
    vector<line> lines;
    //
    bool isMonotonicX;
    function<bool(T l, T r)> comp;
 
public:
    MonotoneCHT(bool flagX,function<bool(T l, T r)> compFunc)
                :isMonotonicX(flagX),comp(compFunc){}
    
    bool check(line l1,line l2,line l3){
        if(l1>l3) swap(l1,l3);
        return (long double)(l3.b-l2.b)*(l1.a-l2.a)<=(long double)(l2.b-l1.b)*(l2.a-l3.a);
    }
 
    void add(T a,T b){
        line l(a,b);
        while(lines.size()>=2 && check(*(lines.end()-2),lines.back(),l)) lines.pop_back();
        lines.emplace_back(l);
    }
 
    T f(int i,T x){
        return lines[i].a*x+lines[i].b;
    }
 
    T f(line l,T x){
        return l.a*x+l.b;
    }
    ///
    T get(T x){
        if(isMonotonicX){
            static int head = 0;
            while(lines.size()-head>=2 && comp(f(head, x), f(head + 1, x))) head++;
            return f(head,x);
        }else{
            int l = 0,r = lines.size();
            while(l+1<r){
                int m = (l+r)/2;
                (comp(f(m-1,x),f(m,x))? r:l) = m;
            }
            return f(l,x);
        }
    }
};
 
int main(){
    int N;
    struct point{
        ll x,y,a;
        bool operator<(const point& r)const{
            return x<r.x;
        }
    };
    scanf("%d",&N);
    vector<point> v(N);
    for(int i=0;i<N;i++){
        ll x,y,a;
        scanf("%lld%lld%lld",&x,&y,&a);
        v[i] = {x,y,a};
    }
    sort(v.begin(),v.end());
    vector<ll> dp(N+1);
    MonotoneCHT<ll> cht(false,[](ll a,ll b){return a>=b;});
    dp[0] = 0;
    cht.add(0,0);
    ll ans = 0;
    for(int i=0;i<N;i++){
        dp[i+1] = v[i].x*v[i].y-v[i].a+cht.get(-v[i].y);
        cht.add(v[i].x,dp[i+1]);
        ans = max(ans,dp[i+1]);
    }
    printf("%lld\n",ans);
}