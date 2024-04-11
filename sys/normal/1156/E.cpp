#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int c,ans,n,p[Maxn],L[Maxn],R[Maxn],sta[Maxn],pos[2*Maxn][21],maxi[2*Maxn][21],cnt;
inline int get_pos(int l,int r)
{
	int siz=log2(r-l+1);
	return maxi[l][siz]<maxi[r-(1<<siz)+1][siz]?pos[r-(1<<siz)+1][siz]:pos[l][siz];
}
set <int> Se[Maxn];
void work(int l,int r,int x)
{
	if(l==r)
		return ;
	int Lpos=0,Rpos=0;
	if(l<=x-1) work(l,x-1,Lpos=get_pos(l,x-1));
	if(x+1<=r) work(x+1,r,Rpos=get_pos(x+1,r));
	if(Lpos&&Rpos)
		for(set <int>::iterator it=Se[Lpos].begin();it!=Se[Lpos].end();it++)
			if(Se[Rpos].find(p[x]-*it)!=Se[Rpos].end()) ans++; 
	if(!Lpos) Se[x].swap(Se[Rpos]);
	else if(!Rpos) Se[x].swap(Se[Lpos]);
	else
	{
		if(Se[Lpos].size()>Se[Rpos].size())
		{ 
			Se[x].swap(Se[Lpos]);
			for(set <int>::iterator it=Se[Rpos].begin();it!=Se[Rpos].end();it++)
				Se[x].insert(*it);
			Se[Rpos].clear();
		}
		else
		{
			Se[x].swap(Se[Rpos]);
			for(set <int>::iterator it=Se[Lpos].begin();it!=Se[Lpos].end();it++)
				Se[x].insert(*it);
			Se[Lpos].clear();
		}
	}
	Se[x].insert(p[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
	{
		while(cnt&&p[sta[cnt]]<p[i])
			R[sta[cnt--]]=i-1;
		sta[++cnt]=i;
	}
	cnt=0;
	for(int i=1;i<=n;i++)
		if(!R[i]) R[i]=n;
	for(int i=n;i>=1;i--)
	{
		while(cnt&&p[sta[cnt]]<p[i])
			L[sta[cnt--]]=i+1;
		sta[++cnt]=i;
	}
	for(int i=1;i<=n;i++)
		if(!L[i]) L[i]=1;
	for(int i=1;i<=n;i++) maxi[i][0]=p[i],pos[i][0]=i,Se[i].insert(p[i]);
	for(int i=1;(1<<i)<=n;i++)
		for(int j=1;j<=n;j++)
		{
			maxi[j][i]=max(maxi[j][i-1],maxi[j+(1<<(i-1))][i-1]);
			if(maxi[j][i]==maxi[j][i-1]) pos[j][i]=pos[j][i-1];
			else pos[j][i]=pos[j+(1<<(i-1))][i-1];
		}
	work(1,n,get_pos(1,n));
	printf("%d",ans);
	return 0;
}