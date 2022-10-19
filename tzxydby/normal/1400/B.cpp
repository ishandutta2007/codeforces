#include<bits/stdc++.h>
using namespace std;
int t,p,f,cnts,cntw,s,w,ans; 
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>p>>f>>cnts>>cntw>>s>>w;
		if(s>w)
		{
			swap(cnts,cntw);
			swap(s,w);
		}
		ans=0;
		for(int i=0;i<=cnts&&i*s<=p;++i)
		{
			int j=min((p-i*s)/w,cntw);
			int k=min(f/s,cnts-i);
			int l=min((f-k*s)/w,cntw-j);
			ans=max(ans,i+j+k+l);	
		}	
		cout<<ans<<endl;	
	}
	return 0;
}