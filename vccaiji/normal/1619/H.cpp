#include<bits/stdc++.h>
using namespace std;
int p[110000];
int p300[110000];
int qq[110000];
int ll[310];
int rr[310];
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int j=1;j<=n;j++) 
	{
		int a=j;
		for(int i=1;i<=100;i++) a=p[a];
		p300[j]=a;
		qq[p[j]]=j;
    }
    bool r=false;
    for(int w=1;w<=q;w++)
    {
    	int t,x,y;
    	scanf("%d%d%d",&t,&x,&y);
    	int px=p[x];
    	int py=p[y];
    	if(t==1)
    	{
    		p[x]=py;
    		p[y]=px;
    		qq[px]=y;
    		qq[py]=x;
    		ll[0]=x;
    		for(int i=1;i<=100;i++) ll[i]=p[ll[i-1]];
    		rr[0]=x;
    		for(int i=1;i<=100;i++) rr[i]=qq[rr[i-1]];
    		for(int i=0;i<=100;i++) p300[rr[i]]=ll[100-i];
    		ll[0]=y;
    		for(int i=1;i<=100;i++) ll[i]=p[ll[i-1]];
    		rr[0]=y;
    		for(int i=1;i<=100;i++) rr[i]=qq[rr[i-1]];
    		for(int i=0;i<=100;i++) p300[rr[i]]=ll[100-i];
		}
		else
		{
			if(r) printf("\n");
			r=true;
			for(int i=0;i<(y/100);i++) x=p300[x];
			for(int i=0;i<(y%100);i++) x=p[x];
			printf("%d",x);
		}
	}
	return 0;
}