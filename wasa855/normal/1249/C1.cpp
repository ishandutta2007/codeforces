#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
int a[105],cnt;
void work()
{
	memset(a,0,sizeof(a));
	int n=read();
	cnt=0;
	while(n)
	{
		a[cnt++]=n%3;
		n/=3;
	}
	cnt--;
	for(int i=cnt;i>=0;i--)
	{
		if(a[i]==2)
		{
			int j=i+1;
			while(a[j]==1) a[j]=0,j++;
			a[j]=1;
			for(int j=i;j>=0;j--) a[j]=0;
			break;
		}
	}
	int ans=0,mul=1;
	for(int i=0;i<=cnt+1;i++)
	{
		ans+=mul*a[i];
		mul*=3;
	}
	cout<<ans<<endl;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}