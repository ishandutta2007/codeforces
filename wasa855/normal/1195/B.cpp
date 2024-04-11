#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int n,k;
	cin>>n>>k;
	int l=0,r=n,mid,ans;
	while(l<=r)
	{
		mid=(l+r)>>1;
//		cout<<l<<" "<<r<<" "<<mid<<endl;
		int res=mid*(mid+1)/2-(n-mid);
		if(res>k) r=mid-1;
		if(res<k) l=mid+1;
		if(res==k)
		{
			ans=mid;break;
		}
	}
	cout<<ans*(ans+1)/2-k<<endl;
#ifndef ONLINE_JUDGE
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}