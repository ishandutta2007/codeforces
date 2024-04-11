#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=1005;
const int M=3*N;
int p[N],rnk[N];
void Init(){ for(int i=0;i<N;i++) p[i]=i;}
int Find(int x){ return x==p[x]?x:p[x]=Find(p[x]);}
void Union(int x, int y)
{
	x=Find(x);y=Find(y);
	if(x==y) return;
	if(rnk[x]>rnk[y]) p[y]=x;
	if(rnk[y]>rnk[x]) p[x]=y;
	if(rnk[x]==rnk[y]) p[x]=y,rnk[y]++;
}
vector<int> pos;
int u[M],v[M],l[M],r[M],n,m;
bool Try(int L, int R)
{
	Init();
	for(int i=1;i<=m;i++) if(L>=l[i] && R<=r[i]) Union(u[i],v[i]);
	return Find(1)==Find(n);
}
int main()
{
	int i;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++) scanf("%i %i %i %i",&u[i],&v[i],&l[i],&r[i]),pos.push_back(l[i]);
	sort(pos.begin(),pos.end());
	pos.erase(unique(pos.begin(),pos.end()),pos.end());
	int top=1000001,bot=1,ans=0,mid;
	while(top>=bot)
	{
		mid=top+bot>>1;
		bool ok=0;
		for(i=0;i<pos.size();i++) ok|=Try(pos[i],pos[i]+mid-1);
		if(ok) ans=mid,bot=mid+1;
		else top=mid-1;
	}
	if(ans) printf("%i\n",ans);
	else printf("Nice work, Dima!\n");
	return 0;
}