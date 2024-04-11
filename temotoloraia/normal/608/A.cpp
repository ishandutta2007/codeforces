#include <iostream>
#include <algorithm>
using namespace std;
int n,s,ans,i;
pair<int,int>p[10001];
main()
{
    cin>>n>>s;
    for (i=0;i<n;i++)
    cin>>p[i].first>>p[i].second;
    sort(p,p+n);
    for (i=n-1;i>=0;i--)
    {
        ans=max(ans+s-p[i].first,p[i].second);
        s=p[i].first;
    }
    cout<<ans+s<<endl;
}