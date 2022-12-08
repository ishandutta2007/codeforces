#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
struct pt{ll x,y;} st,ed;
ll work(ll x,ll y,ll a,ll b,ll c) {
    return (x*a+b*y+c>0)?1:-1;
}
int main() {
    cin>>st.x>>st.y>>ed.x>>ed.y;
    int n;scanf("%d",&n);int ans=0;
    while (n--) {
        ll a,b,c;cin>>a>>b>>c;
        if (work(st.x,st.y,a,b,c)*work(ed.x,ed.y,a,b,c)==-1) ++ans;
    }
    cout<<ans<<endl;
    return 0; 
}