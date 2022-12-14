#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
    {
        int n,x,a,b;
        cin>>n>>x>>a>>b;
        int ans=abs(a-b);
        ans=min(n-1,ans+x);
        cout<<ans<<endl;
    }
	return 0;
}