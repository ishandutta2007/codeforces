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
#define N 100005
char s[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	scanf("%s",s+1);
	int n=strlen(s+1);
	if(n%2==1)
	{
		bool ha=0;
		for(int i=2;i<=n;++i)
		{
			if(s[i]=='1')
			{
				ha=1;
			}
		}
		if(ha)
		{
			cout<<n/2+1<<endl;
		}
		else
		{
			cout<<n/2<<endl;
		}
	}
	else
	{
		cout<<n/2<<endl;
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}