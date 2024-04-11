#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define ll long long
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
#define N 200005
int ans[N],p[N],cur[N];
char s[N];
void work()
{
	for(int i=0;i<30;i++) ans[i]=0;
	for(int i=0;i<30;i++) cur[i]=0;
	int n,m;
	cin>>n>>m; scanf("%s",s+1);
	for(int i=1;i<=m;i++) p[i]=read(); sort(p+1,p+m+1);
	int cc=0;
	for(int i=1;i<=m;i++)
	{
		while(cc<p[i])
		{
			cc++; cur[s[cc]-'a']++;
		}
		for(int i=0;i<26;i++) ans[i]+=cur[i];
	}
	for(int i=1;i<=n;i++) ans[s[i]-'a']++;
	for(int i=0;i<26;i++) printf("%d ",ans[i]);
	cout<<"\n";
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}