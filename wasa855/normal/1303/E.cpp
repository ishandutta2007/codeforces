#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 405
int f[N][N],n,m;
char s[N],t[N];
char a[N],b[N];
int nxt[N][N];
int la,lb;
bool judge(int x)
{
	la=x,lb=m-x;
	for(int i=1;i<=x;i++) a[i]=t[i];
	for(int i=x+1;i<=m;i++) b[i-x]=t[i];
	for(int i=1;i<=la;i++) f[i][0]=nxt[f[i-1][0]][a[i]-'a'];
	for(int i=1;i<=lb;i++) f[0][i]=nxt[f[0][i-1]][b[i]-'a'];
	for(int i=1;i<=la;i++)
	{
		for(int j=1;j<=lb;j++)
		{
			f[i][j]=min(nxt[f[i-1][j]][a[i]-'a'],nxt[f[i][j-1]][b[j]-'a']);
		}
	}
//	printf("%d %d\n",la,lb);
//	for(int i=0;i<=la;i++)
//	{
//		for(int j=0;j<=lb;j++) printf("%d ",f[i][j]);
//		cout<<"\n";
//	}
	return f[la][lb]<=n;
}
void work()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i]==t[1])
			{
				cout<<"YES\n";
				return ;
			}
		}
		cout<<"NO\n";
		return ;
	}
	for(int j=0;j<26;j++) nxt[n+1][j]=n+1;
	for(int i=n;i>=0;i--)
	{
		for(int j=0;j<26;j++)
		{
			if(s[i+1]-'a'==j) nxt[i][j]=i+1;
			else nxt[i][j]=nxt[i+1][j];
		}
	}
//	for(int i=0;i<=n;i++)
//	{
//		for(int j=0;j<26;j++) printf("%d ",nxt[i][j]);
//		cout<<"\n";
//	}
	for(int i=1;i<=m-1;i++)
	{
		if(judge(i))
		{
			cout<<"YES\n";
			return ;
		}
	}
	cout<<"NO\n";
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}