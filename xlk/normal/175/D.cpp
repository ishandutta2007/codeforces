#include<stdio.h>
#include<iostream>
double eps=1e-7;
using namespace std;
double v1[220];
double v2[220];
double ans;
int hp1,dt1,l1,r1,p1,t1;
int hp2,dt2,l2,r2,p2,t2;
int att(double *v,int l,int r,int p)
{
	int re=0;
	for(int i=1;i<=200;i++)
	{
		if(v[i]<eps)
			continue;
		re=1;
		double w=(1-p*0.01)/(r-l+1)*v[i];
		v[i]*=p*0.01;
		for(int j=l;j<=r;j++)
			v[max(i-j,0)]+=w;
	}
	return re;
}
int main()
{
	cin>>hp1>>dt1>>l1>>r1>>p1; 
	cin>>hp2>>dt2>>l2>>r2>>p2;
	if(p1==100)
		return printf("0"),0;
	else if(p2==100)
		return printf("1"),0;
	v1[hp1]=v2[hp2]=1;
	while(1)
	{
		if(t1<=t2)
		{
			t1+=dt1;
			v2[0]=0;
			att(v2,l1,r1,p1);
			ans+=(1-v1[0])*v2[0];
		}
		else
		{
			t2+=dt2;
			if(!att(v1,l2,r2,p2))
				break;
		}
	}
	printf("%.10f",ans);
	return 0;	
}