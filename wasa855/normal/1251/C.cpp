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
#define N 300005
char s[N];
int a[N];
int suf[N];
int odd[N],eve[N];
void work()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++) a[i]=s[i]-'0';
	int co=0,ce=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]&1) odd[++co]=a[i];
		else eve[++ce]=a[i];
	}
	int i=1,j=1;
	for(int k=1;k<=n;k++)
	{
		if(j==ce+1||(i!=co+1&&odd[i]<eve[j])) printf("%d",odd[i++]);
		else printf("%d",eve[j++]);
	}
	cout<<"\n";
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