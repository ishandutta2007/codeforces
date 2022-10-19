#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
} 
double ans[1001][1001];
double findans(int nb,int nh)
{
	if(nh<0||nb<0)return 0;
	if(nb==0)return 0;
	if(nh==0)return 1;
	if(nh==1)return 1.0*nb/(nb+nh);
	if(ans[nb][nh]!=0)return ans[nb][nh];
	return ans[nb][nh]=1.0*nb/(nb+nh)+1.0*nh/(nb+nh)*1.0*(nh-1)/(nb+nh-1)*(1.0*nb/(nb+nh-2)*findans(nb-1,nh-2)+1.0*(nh-2)/(nb+nh-2)*findans(nb,nh-3));
}
int main()
{
    int n,m;
    n=read();
    m=read();
    printf("%.9lf",findans(n,m));
    return 0;
}
//tll qiang qiang