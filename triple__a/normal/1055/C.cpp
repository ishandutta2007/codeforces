#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int>
 
using namespace std;
 
typedef long long ll;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll a,b,c,d,e,f;

ll common(ll u,ll v,ll x,ll y){
//    cout<<u<<" "<<v<<" "<<x<<" "<<y<<endl;
    return max(0ll,min(v,y)-max(u,x)+1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>a>>b>>c>>d>>e>>f;
    if (a>d){
        swap(a,d), swap(b,e), swap(c,f);
    }
    ll x=__gcd(c,f);
    ll ls=(d-a)/x, rs=ls+1;
    cout<<max(common(a+ls*x,b+ls*x,d,e),common(a+rs*x,b+rs*x,d,e));
    return 0;
}