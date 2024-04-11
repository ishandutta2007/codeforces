#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define rrep(i,l,r) for(int i=(r-1);i>=(l);i--)
#define LINF (ll)1e18
#define INF (int)1e9
#define range(i) i.begin(),i.end()
#define Yes(i) out(i?"Yes":"No");return 0
struct aaa{aaa(){cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(10);};}aaaaaaa;
inline void in() {}
template <class Head, class... Tail>
inline void in(Head&& head,Tail&&... tail){
    cin>>head;
    in(move(tail)...);
}
template <class T>
inline void out(T t) {
    cout<<t<<'\n';
}
template <class Head, class... Tail>
inline void out(Head head,Tail... tail){
    cout<<head<<' ';
    out(move(tail)...);
}

int main(){
    int n,h,a,b,k;
    in(n,h,a,b,k);
    rep(i,0,k){
        int c,d,e,f;
        in(c,d,e,f);
        if(c==e)out(abs(d-f));
        else if(min(d,f)>b)out(d-b+f-b+abs(c-e));
        else if(max(d,f)<a)out(a-d+a-f+abs(c-e));
        else out(abs(d-f)+abs(c-e));
    }
}