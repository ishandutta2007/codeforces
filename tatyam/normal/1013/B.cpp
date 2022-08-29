#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,l,r) for(int i=(l);i<(r);i++)
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
    int n,x;
    in(n,x);
    deque<pair<int,int>>a;
    int b;
    rep(i,0,n){
        in(b);
        a.push_back(make_pair(b, 0));
        if((b&x)-b)a.push_back(make_pair(b&x, 1));
    }
    sort(a.begin(), a.end());
    int min=INF;
    rep(i,1,a.size())if(a[i].first==a[i-1].first&&min>a[i].second+a[i-1].second)min=a[i].second+a[i-1].second;
    out((min-INF)?min:-1);
}