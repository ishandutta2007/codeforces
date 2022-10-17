#include<stdio.h>
#include<iostream>
using namespace std;
char s[1000020];
char o[20];
struct N
{
	int l,r,rv;
	int c4,c7,c47,c74;
}t[4000020];
void mg(int x)
{
	t[x].c4=t[x*2].c4+t[x*2+1].c4;
	t[x].c7=t[x*2].c7+t[x*2+1].c7;
	t[x].c47=max(t[x*2].c47+t[x*2+1].c7,t[x*2].c4+t[x*2+1].c47);
	t[x].c74=max(t[x*2].c74+t[x*2+1].c4,t[x*2].c7+t[x*2+1].c74);
}
void bd(int l,int r,int x)
{
	t[x].l=l;
	t[x].r=r;
	if(l<r)
	{
		bd(l,l+r>>1,x*2);
		bd((l+r>>1)+1,r,x*2+1);
	}
	else
	{
		t[x].c4=(s[l]=='4');
		t[x].c7=(s[l]=='7');
		t[x].c74=t[x].c47=1;
		return;
	}
	mg(x);
}
void rev(int x)
{
	swap(t[x].c4,t[x].c7);
	swap(t[x].c47,t[x].c74);
	t[x].rv^=1;
}
void cg(int l,int r,int x)
{
	if(t[x].rv&&t[x].l<t[x].r)
	{
		rev(2*x),rev(2*x+1);
		t[x].rv=0;
	}
	if(t[x].l>=l&&t[x].r<=r)
		return rev(x);
	if(r<=(t[x].l+t[x].r)/2)
		cg(l,r,2*x);
	else if(l>(t[x].l+t[x].r)/2)
		cg(l,r,2*x+1);
	else
		cg(l,r,2*x),cg(l,r,2*x+1);
	mg(x);
	return;
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);	
	scanf("%s",s+1);
	bd(1,n,1);
	while(m--)
	{
		scanf("%s",o);
		if(*o=='s')
		{
			int x,y;
			scanf("%d %d",&x,&y);
			cg(x,y,1);
		}
		else
			printf("%d\n",t[1].c47);	
	}
	return 0;
}