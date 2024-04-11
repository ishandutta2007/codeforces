//
//
#include<bits/stdc++.h>
using namespace std;
int n,q,t[4000005],a[1000005],qwq=0;
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
void build(int x,int l,int r)
{
	int md;if(l==r) return(void)(scanf("%d",&t[x]));else md=(l+r)>>1;
	build(x<<1,l,md),build(x<<1|1,md+1,r),t[x]=gcd(t[x<<1],t[x<<1|1]);
}
void query(int x,int l,int r,int dl,int dr,int d)
{
	int md;if(qwq>1) return;else if(l==r) return(void)(++qwq);else md=(l+r)>>1;
	if(md>=dl&&t[x<<1]%d) query(x<<1,l,md,dl,dr,d);
	if(md<dr&&t[x<<1|1]%d) query(x<<1|1,md+1,r,dl,dr,d);
}
void chang(int x,int l,int r,int dw,int dc)
{
	int md;if(l==r) return(void)(t[x]=dc);else md=(l+r)>>1;
	if(dw<=md) chang(x<<1,l,md,dw,dc),t[x]=gcd(t[x<<1],t[x<<1|1]);
	else chang(x<<1|1,md+1,r,dw,dc),t[x]=gcd(t[x<<1],t[x<<1|1]);
}
int main()
{
	for(scanf("%d",&n),build(1,1,n),scanf("%d",&q);q--;)
	{
		int fg,l,r,w;scanf("%d%d%d",&fg,&l,&r);
		if(fg==2) {chang(1,1,n,l,r);continue;}
		scanf("%d",&w),qwq=0,query(1,1,n,l,r,w);
		puts(qwq>1?"NO":"YES");
	}
	return 0;
}