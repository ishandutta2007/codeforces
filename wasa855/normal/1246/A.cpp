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
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,p;
	cin>>n>>p;
	if(p>=n)
	{
		cout<<"-1\n";return 0;
	}
	for(int i=0;;i++)
	{
		int now=n-i*p;
		if(now<=0) break;
		int sum=0,maxn=0;
		for(int j=0;j<=32;j++)
		{
			if(now&(1LL<<j)) sum++,maxn+=j+1;
		}
		if(sum<=i&&maxn>=i)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"-1\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}