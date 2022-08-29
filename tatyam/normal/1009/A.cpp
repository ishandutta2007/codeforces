#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,l,r) for(ll i=l;i<r;i++)
#define INF (ll)1e18
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
    int a,b,cnt=0,c;
    in(a,b);
    vector<int>cost(a);
    queue<int>value;
    rep(i,0,a)in(cost[i]);
    rep(i,0,b){in(c);value.push(c);}
    rep(i,0,a&&!value.empty())if(value.front()>=cost[i]){
        cnt++;
        value.pop();
    }
    out(cnt);
}