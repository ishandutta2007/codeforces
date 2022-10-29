#include <bits/stdc++.h>
using namespace std;
double a,b,c,v,ans;
inline void dfs(double a,double b,double c,double p,double st)
{
	if(a>=1e-9) 
	{
		if(a>v)
		{
			if(b<=1e-9) dfs(a-v,b,c+v,p*a,st+1);
			else dfs(a-v,b+v/2,c+v/2,p*a,st+1);
		}
		else
		{
			if(b<=1e-9) dfs(0,0,1,p*a,st+1);
			else dfs(0,b+a/2,c+a/2,p*a,st+1);
		}
	}
	
	
	if(b>=1e-9) 
	{
		if(b>v)
		{
			if(a<=1e-9) dfs(a,b-v,c+v,p*b,st+1);
			else dfs(a+v/2,b-v,c+v/2,p*b,st+1);
		}
		else
		{
			if(a<=1e-9) dfs(0,0,1,p*b,st+1);
			else dfs(a+b/2,0,c+b/2,p*b,st+1);
		}
	}
//	cout << a << " " << b << " " << c << " " << p << "\t" << st << "\n";
//	cout << p*c*(st+1) << "**\n";
	ans+=p*c*(st+1);
}
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> a >> b >> c >> v;
		dfs(a,b,c,1,0);
		printf("%.15lf\n",ans); 
		ans=0;
	}
	return 0;
}