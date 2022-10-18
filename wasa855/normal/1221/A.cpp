#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 105
int cnt[N];
void work()
{
	memset(cnt,0,sizeof(cnt));
	int n=read();
	for(int i=1;i<=n;i++)
	{
		int t=read();
		int x=0,r=1;
		while(t!=r)
		{
			r*=2,x++;
		}
//		cout<<x<<endl;
		cnt[x]++;
	}
	while(cnt[11]==0)
	{
		bool ok=false;
		for(int i=10;i>=0;i--)
		{
			if(cnt[i]>=2)
			{
				ok=true;
				cnt[i+1]+=cnt[i]/2;
				cnt[i]%=2;
			}
		}
		if(ok==false) break;
	}
	if(cnt[11])
	{
		cout<<"YES\n";
	}
	else cout<<"NO\n";
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--)
	{
		work();
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//