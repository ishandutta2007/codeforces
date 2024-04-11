#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define Rep(i,a,b) for(int i=(a);i<=(b);++i)
vector<pair<int,int> > ans;
int a[N],b[N];
int f[233][233],n,fa[233];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	scanf("%d",&n);
	Rep(i,1,n)
	 {
		a[i]=getchar();
		while(a[i]<'a'||a[i]>'z')a[i]=getchar();
		a[i]-='a';
	 }
	Rep(i,1,n)
	 {
		b[i]=getchar();
		while(b[i]<'a'||b[i]>'z')b[i]=getchar();
		b[i]-='a';
	 }
	Rep(i,1,n)
	 {
		f[a[i]][b[i]]=1;
		f[b[i]][a[i]]=1;
	 }
	rep(i,0,26)fa[i]=i;
	for (int i=0;i<26;i++)
	 for (int j=i+1;j<26;j++)
	  if (f[i][j])
	   if (find(i)!=find(j))
	    {
			fa[find(i)]=find(j);
			ans.push_back({i+'a',j+'a'});
		}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++)
	 printf("%c %c\n",ans[i].first,ans[i].second);
	return 0;
}