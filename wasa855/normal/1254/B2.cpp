#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 1000005
int a[N];
int n;
int calc(int x)
{
	int tmp=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		tmp=(tmp+a[i])%x;
		ans+=min(tmp,x-tmp);
	}
	return ans;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	n=read();
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		sum+=a[i];
	}
	if(sum==1)
	{
		cout<<"-1\n";
		return 0;
	}
	int ans=calc(sum);
	for(int i=2;i*i<=sum;i++)
	{
		if(sum%i==0)
		{
			while(sum%i==0) sum/=i;
			int x=calc(i);
			if(x<ans) ans=x;
		}
	}
	if(sum>1)
	{
		int x=calc(sum);
		if(x<ans) ans=x;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}