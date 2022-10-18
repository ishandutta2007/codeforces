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
int a[N];
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int siz[N];
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		fa[find(a[i])]=find(i);
	}
	for(int i=1;i<=n;i++) siz[i]=0;
	for(int i=1;i<=n;i++) siz[find(i)]++;
	for(int i=1;i<=n;i++) printf("%d ",siz[find(i)]);
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

//