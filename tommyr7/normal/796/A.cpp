#include <bits/stdc++.h>
#define inf 1000000007
using namespace std;
int n,m,k,ans;
int main()
{
    cin>>n>>m>>k;
    ans=inf;
    for (int i=1;i<=n;i++)
    {
       int t;
       cin>>t;
       if (t>0&&t<=k&&(abs(i-m)<ans)) ans=abs(i-m);
    }
    cout << ans*10 << endl;
    return 0;
}