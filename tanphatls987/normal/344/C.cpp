#include <iostream>
using namespace std;
int64_t x,y,ans,tmp;
int solve()
{
    ans+=x/y;x=x%y;
    if (!x) return(0);
    if (x==1) {ans+=y;return(0);}
    tmp=x;x=y-x;y=tmp;
    ans++;
    solve();
}
int main()
{
    cin>>x>>y;
    ans=0;
    solve();
    cout<<ans;
}