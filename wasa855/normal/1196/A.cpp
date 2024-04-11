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
int a[4];
void work()
{
	a[1]=read(),a[2]=read(),a[3]=read();
	sort(a+1,a+4);
	int x=a[1],y=a[2],z=a[3];
	int ans=(x+y+z)/2;
	if(ans-x<=z&&ans-y<=z)
	{
		cout<<ans<<endl;
	}
	else
	{
		cout<<min(x,y)+z<<endl;
	}
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int T;
	cin>>T;
	while(T--) work();
#ifndef ONLINE_JUDGE
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}