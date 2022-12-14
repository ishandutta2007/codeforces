#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 200005
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
struct Segment
{
	int lmx,lmn,rmx,rmn,a,b,ans;
	Segment(){ans=lmx=rmx=lmn=rmn=a=b=0;}
	Segment(int _,int __,int ___,int ____,int _____,int ______,int _______)
		{lmx=_,lmn=__,rmx=___,rmn=____,a=_____,b=______,ans=_______;}
	Segment(int op){if(!op)lmx=lmn=rmx=b=ans=1,rmn=a=0;else lmx=rmx=rmn=a=ans=1,lmn=b=0;}
	friend Segment operator + (const Segment &L,const Segment &R)
	{
		Segment c=Segment();
		c.lmx=max(L.lmx,max(L.a+L.b+R.lmn,L.a-L.b+R.lmx));
		c.rmx=max(R.rmx,max(R.a+R.b+L.rmn,R.b-R.a+L.rmx));
		c.lmn=max(L.lmn,R.lmn+L.b-L.a);c.rmn=max(R.rmn,L.rmn+R.a-R.b);
		c.a=L.a+max(R.a-L.b,0),c.b=R.b+max(L.b-R.a,0);
		c.ans=max(max(L.ans,R.ans),max(L.rmx+R.lmn,L.rmn+R.lmx));
		return c;
	}
}tr[N<<2];
char s[N];int n,Q;
void build(int l,int r,int rt)
{
	// printf("%d %d\n",l,r);
	if(l==r)return tr[rt]=Segment(s[l]==')'),void();int m=(l+r)>>1;
	build(lson),build(rson);tr[rt]=tr[rt<<1]+tr[rt<<1|1];
}
void Update(int p,int l,int r,int rt)
{
	if(l==r)return tr[rt]=Segment(s[l]==')'),void();int m=(l+r)>>1;
	if(p<=m)Update(p,lson);else Update(p,rson);tr[rt]=tr[rt<<1]+tr[rt<<1|1];
}
int main()
{
	scanf("%d%d%s",&n,&Q,s+1);n--;n<<=1;build(1,n,1);printf("%d\n",tr[1].ans);
	for(int x,y;Q--;printf("%d\n",tr[1].ans))scanf("%d%d",&x,&y),swap(s[x],s[y]),Update(x,1,n,1),Update(y,1,n,1);
}