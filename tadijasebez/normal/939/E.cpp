#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
const int N=500050;
double max(double a, double b){ return a>b?a:b;}
vector<double> pre;
int main()
{
	double sol=0;
	int q,i,t,x,cnt=0,top,bot,mid,ans;
	ll sum=0;
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i",&x);
			sum+=x;
			cnt++;
			top=pre.size()-2;
			bot=0;
			ans=pre.size()-1;
			while(top>=bot)
			{
				mid=top+bot>>1;
				//printf("%i %.5llf %.5llf\n",mid,(double)x/(mid+2)+pre[mid],(double)x/(mid+3)+pre[mid+1]);
				if((double)x/(mid+2)+pre[mid]<(double)x/(mid+3)+pre[mid+1]) ans=mid,top=mid-1;
				else bot=mid+1;
			}
			if(ans>=0) sol=max(sol,(double)x-((double)x/(ans+2)+pre[ans]));
			pre.push_back((double)sum/(cnt+1));
			//double tmp=(double)x-(double)sum/cnt;
			//printf("%.5llf %.5llf\n",tmp,(double)sum/cnt);
			//sol=max(sol,(double)x-(double)sum/cnt);
		}
		else printf("%.10llf\n",sol);
	}
	return 0;
}