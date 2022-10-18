#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans; return ans;
}
void work()
{
	int n,k;
	n=read(),k=read();
	if(n==1||n==2||n==k)
	{
		cout<<"Alice\n";
		return ;
	}
	if(k%3==0)
	{
		int x=n%(k+1);
		if(x==0)
		{
			cout<<"Bob\n";
			return ;
		}
		if(x!=k&&x%3==0)
		{
			cout<<"Bob\n";
			return ;
		}
		cout<<"Alice\n";
		return ;
	}
	if(n%3==0)
	{
		cout<<"Bob\n";
	}
	else cout<<"Alice\n";
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
 //adscafe