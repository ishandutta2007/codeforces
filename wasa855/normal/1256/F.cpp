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
char a[N],b[N];
int cnta[30];
int cntb[30];
void work()
{
	for(int i=0;i<26;i++) cnta[i]=0;
	for(int i=0;i<26;i++) cntb[i]=0;
	int n;
	cin>>n;
	scanf("%s\n%s",a+1,b+1);
	for(int i=1;i<=n;i++) cnta[a[i]-'a']++;
	for(int i=1;i<=n;i++) cntb[b[i]-'a']++;
	for(int i=0;i<26;i++)
	{
		if(cnta[i]!=cntb[i])
		{
			cout<<"NO\n";
			return ;
		}
	}
	for(int i=0;i<26;i++)
	{
		if(cnta[i]>=2)
		{
			cout<<"YES\n";
			return ;
		}
	}
	int ra=0,rb=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]>a[j]) ra++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(b[i]>b[j]) rb++;
		}
	}
	int res=abs(ra-rb);
	if(res%2==0) cout<<"YES\n";
	else cout<<"NO\n";
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