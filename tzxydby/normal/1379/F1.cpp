#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,Q,mn[N<<2],mx[N<<2],fl[N<<2];
set<int>SL[N],SR[N];
map<pair<int,int>,int>mp;
void pushup(int k)
{
	mn[k]=max(mn[k*2],mn[k*2+1]);
	mx[k]=min(mx[k*2],mx[k*2+1]);
	fl[k]=fl[k*2]|fl[k*2+1]|(mn[k*2+1]>=mx[k*2]);
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		mn[k]=0;
		mx[k]=m+1;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	pushup(k);
}
void change(int k,int l,int r,int p)
{
	if(l==r)
	{
		mn[k]=(SL[l].size()?*SL[l].rbegin():0);
		mx[k]=(SR[l].size()?*SR[l].begin():m+1);
		fl[k]=(mn[k]>=mx[k]);
		return;
	}
	int mid=(l+r)/2;
	if(p<=mid) change(k*2,l,mid,p);
	else change(k*2+1,mid+1,r,p);
	pushup(k);
}
int main()
{
	scanf("%d%d%d",&n,&m,&Q);
	build(1,1,n);
	while(Q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x++,y++;
		if(mp[pair<int,int>(x,y)])
		{
			if(y&1) 
				SL[x>>1].erase(y>>1);
			else 
				SR[x>>1].erase(y>>1);
		}
		else
		{
			if(y&1) 
				SL[x>>1].insert(y>>1);
			else 
				SR[x>>1].insert(y>>1);
		}
		mp[pair<int,int>(x,y)]^=1;
		change(1,1,n,x>>1);
		puts(fl[1]?"NO":"YES");
	}
	return 0;
}