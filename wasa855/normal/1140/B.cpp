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
char s[N];
void work()
{
	int n=read();
	scanf("%s",s+1);
	int minn=n;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='>')
		{
			minn=min(minn,i-1);
			break;
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(s[i]=='<')
		{
			minn=min(minn,n-i);
			break;
		}
	}
	cout<<minn<<endl;
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