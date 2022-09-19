#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int floor(int x,int y)
{
    if(x>0) return (x/y);
    else return (x-(y-1))/y;
}
mt19937 rnd;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;int a1,a2,b1,b2;cin>>a1>>a2>>b1>>b2;int mod=abs(a1*b2-a2*b1);if(mod==0) {cout<<"NO";return 0;}
    if(mod!=n) {cout<<"NO";return 0;}
    set<pair<int,int> > s;
    if(b1*a2-a1*b2<0) {swap(a1,b1);swap(a2,b2);}
    for(int cyc=0;cyc<2e6;++cyc)
    {
        int x=rnd();int y=rnd();x=abs(x);y=abs(y);
        int beta=floor((x*a2-y*a1),(b1*a2-a1*b2));
        int alpha=floor((-x*b2+y*b1),(b1*a2-a1*b2));
        x-=alpha*a1+beta*b1;y-=alpha*a2+beta*b2;
        s.insert({x,y});
    }
    cout<<"YES"<<endl;
    for(auto h:s)
    {
        cout<<h.first<<' '<<h.second<<endl;
    }
    return 0;
}