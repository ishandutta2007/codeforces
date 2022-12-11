#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n,m,i,j,mx1=0,mx2=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        mx1=max(mx1,a);
    }
    cin>>n;
    cout<<mx1<<' ';
    mx1=0;
    for(i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        mx1=max(mx1,a);
    }
    cout<<mx1;
	return 0;
}