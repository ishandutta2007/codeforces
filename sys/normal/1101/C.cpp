#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int n,T,cnt,bel[Maxn];
bool tag;
struct line
{
	int pos,id;
	bool is_l;
	bool operator < (const line &tmp) const
	{
		if(pos!=tmp.pos) return pos<tmp.pos;
		return is_l>tmp.is_l;
	}
}L[2*Maxn];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		tag=false;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			L[2*i-1].pos=l,L[2*i-1].id=i,L[2*i-1].is_l=true;
			L[2*i].pos=r,L[2*i].id=i,L[2*i].is_l=false;
		}
		sort(L+1,L+1+2*n);
		for(int i=1;i<=2*n;i++)
		{
			if(L[i].is_l) cnt++;
			else cnt--;
			bel[L[i].id]=tag;
			if(!cnt&&i!=2*n) tag=true;
		}
		if(!tag) printf("-1\n");
		else
		{
			for(int i=1;i<=n;i++)
				printf("%d ",bel[i]+1);
			printf("\n");
		}
	}
	return 0;
}