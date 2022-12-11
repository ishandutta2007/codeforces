#include<bits/stdc++.h>
using namespace std;
inline vector<int> calc_div(int v)
{
	vector<int> res;
	for(int i=1;i*i<=v;++i)
	{
		if(v%i==0)
		{
			res.push_back(i);
			if(i*i!=v)
				res.push_back(v/i);
		}
	}
	return res;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		vector<int> Div_a=calc_div(a);
		vector<int> Div_b=calc_div(b);
		bool exist=false;
		for(int p:Div_a)
		{
			for(int q:Div_b)
			{
				long long n=1ll*p*q,m=1ll*a*b/n;
				int x=c/n*n,y=d/m*m;
				if(x>a&&y>b)
				{
					printf("%d %d\n",x,y);
					exist=true;
					break;
				}
			}
			if(exist)
				break;
		}
		if(!exist)
			puts("-1 -1");
	}
	return 0;
}