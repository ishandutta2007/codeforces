#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm>
#include<cstdlib>
using namespace std;
int n,s,i,j,x,y,z,a,b,c,aa,ab,ac,ans,cnt;
int main()
{
	cin>>n>>s;
	for(i=1;i<=n;i++)
	{
		cin>>j;
		if(j==3) x++;
		if(j==4) y++;
		if(j==5) z++;
	}
	n=x+y+z;
	ans=0x3fffffff;
	for(a=s/n;a>=0;a--)
		for(b=min((s-a*x)/(y+z),(ans+a*x)/y);b>=a;b--)
		{
			if(a*x-b*y>=ans) break;
			c=(s-a*x-b*y)/z;
			if(c*z-b*y>=ans) break;
			if(a*x+b*y+c*z!=s) continue;
			if(abs(a*x-b*y)+abs(b*y-c*z)<ans)
			{
				ans=abs(a*x-b*y)+abs(b*y-c*z);
				aa=a,ab=b,ac=c;
			}
			cnt++;
			if(cnt>300000000) {a=1; break;}
		}
	if(ans!=0x3fffffff) cout<<aa<<' '<<ab<<' '<<ac<<endl;	else puts("-1"); 
	return 0;
}