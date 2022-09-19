#include <bits/stdc++.h>

using namespace std;
#define int long long
int y;
set <int> u;
int rev(int x)
{
    int m=0;
    while(x>=(1LL<<m)) ++m;
    int ans=0;
    for(int i=0;i<m;++i) if(x & (1LL<<i)) ans+=(1LL<<(m-i-1));
    return ans;
}
void go(int x)
{
    if(x==y)
    {
        cout<<"YES";
        exit(0);
    }
    if(u.count(x) || x>2e18) return;
    u.insert(x);
    int x1=rev(2*x);
    go(x1);int y1=rev(2*x+1);go(y1);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int x;
    cin>>x>>y;
    go(x);
    cout<<"NO";
    return 0;
}