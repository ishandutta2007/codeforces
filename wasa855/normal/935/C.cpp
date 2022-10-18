#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
int main()
{
	double r,x1,y1,x2,y2;
	cin>>r>>x1>>y1>>x2>>y2;
	double dist=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	if(dist>=r)
	{
		printf("%.7lf %.7lf %.7lf\n",x1,y1,r);
		return 0;
	}
	double R=(r+dist)/2;
	double ang=atan2(y1-y2,x1-x2);
	printf("%.7lf %.7lf %.7lf\n",x2+cos(ang)*R,y2+sin(ang)*R,R);
	return 0;
}