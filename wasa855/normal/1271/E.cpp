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
int n,k;
int f(int x,int dep)
{
	return max(0LL,min(1LL<<dep,n-(x<<dep)+1));
}
int work(int x)
{
	int ans=0;
	for(int i=0;(x<<i)<=n;i++)
	{
		ans+=f(x,i);
		if(x%2==0) ans+=f(x+1,i);
	}
	return ans;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n>>k;
	int ans=0;
	for(int i=60;i>=0;i--)
	{
		if(work(ans|(1LL<<i))>=k) ans|=(1LL<<i);
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}