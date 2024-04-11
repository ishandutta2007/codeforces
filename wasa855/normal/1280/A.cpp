#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define mod 1000000007
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 1000005
char s[N];
void work()
{
	int x;
	cin>>x;
	scanf("%s",s+1);
	int n=strlen(s+1);
	int ans=n;
	bool mo=0;
	for(int i=1;i<=x;i++)
	{
		if(s[i]=='2')
		{
			if(mo==1)
			{
				ans+=ans-i;
				ans%=mod;
				ans=(ans+mod)%mod;
				continue;
			}
			for(int k=1;k<=ans-i;k++)
			{
				if(ans+k>x)
				{
					mo=1;break;
				}
				s[ans+k]=s[i+k];
			}
			ans+=ans-i;
			ans%=mod;
				ans=(ans+mod)%mod;
		}
		if(s[i]=='3')
		{
			if(mo==1)
			{
				ans+=2*(ans-i);
				ans%=mod;
				ans=(ans+mod)%mod;
				continue;
			}
			for(int k=1;k<=ans-i;k++)
			{
				if(ans+k>x)
					{
						mo=1;break;
					}
				s[ans+k]=s[i+k];
			}
			for(int k=1;k<=ans-i;k++)
			{
				if(ans+ans-i+k>x)
					{
						mo=1;break;
					}
				s[ans+ans-i+k]=s[i+k];
			}
			ans+=2*(ans-i);
				ans%=mod;
				ans=(ans+mod)%mod;
		}
//		cout<<ans<<endl;
//		for(int i=1;i<=ans;i++) printf("%c",s[i]);
//		cout<<"\n";
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
//