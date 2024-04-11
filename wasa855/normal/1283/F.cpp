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
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
#define N 200005
int a[N],x[N],y[N];
int fa[N];
bool vis[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	int maxn=n,las=1;
	a[1]=read();
	if(maxn==a[1]) maxn--;
	x[1]=a[1],y[1]=maxn;
	vis[a[1]]=1,vis[maxn]=1;
	for(int i=2;i<n;i++)
	{
		a[i]=read();
		if(vis[a[i]])
		{
			while(vis[maxn]) maxn--;
			x[i]=a[i],y[i]=maxn;
			las=i;
		}
		else
		{
			x[i]=a[i],y[i]=maxn;
			y[las]=x[i];
			las=i;
		}
		vis[x[i]]=vis[y[i]]=1;
	}
	cout<<a[1]<<endl;
	for(int i=1;i<n;i++) printf("%d %d\n",x[i],y[i]);
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}