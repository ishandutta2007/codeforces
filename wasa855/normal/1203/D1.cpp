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
#define N 200005
char s[N],t[N];
int l[N],r[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1),m=strlen(t+1);
	int j=1;
	for(int i=1;i<=n&&j<=m;i++)
	{
		if(s[i]==t[j]) l[j++]=i;
	}
	j=m;
	for(int i=n;i>=1&&j>=1;i--)
	{
		if(s[i]==t[j]) r[j--]=i;
	}
	int ans=max(r[1]-1,n-l[m]);
	for(int i=1;i<n;i++)
	{
		if(r[i+1]-l[i]-1>ans) ans=r[i+1]-l[i]-1;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}