#include<bits/stdc++.h>
using namespace std;
const int N=400005;
set<pair<int,int>>s;
int tr[N<<2],a[N<<2],n,m,k;
void update(int k,int l,int r,int x,int v)
{
	if(l==r)
	{
		a[k]+=v;
		tr[k]=a[k]?l+a[k]-1:0;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) update(k<<1,l,mid,x,v);
	else update(k<<1|1,mid+1,r,x,v);
	a[k]=a[k<<1]+a[k<<1|1];
	tr[k]=max(tr[k<<1|1],tr[k<<1]+a[k<<1|1]);
}
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(s.count(make_pair(x,y)))
		{
			update(1,1,400000,y+abs(x-k),-1);
			s.erase(make_pair(x,y));
		}
		else
		{
			update(1,1,400000,y+abs(x-k),1);
			s.insert(make_pair(x,y));
		}
		printf("%d\n",max(0,tr[1]-n));
	}
	return 0;
}