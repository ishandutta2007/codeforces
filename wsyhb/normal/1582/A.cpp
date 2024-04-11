#include<bits/stdc++.h>
using namespace std;
inline int calc(int x,int y)
{
	return x>=y?x-y:y-x;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int ans=6;
		for(int i=0;i<=min(a,10);++i)
			for(int j=0;j<=min(b,10);++j)
				for(int k=0;k<=min(c,10);++k)
				{
					if((a-i)%2==0&&(b-j)%2==0&&(c-k)%2==0)
					{
						ans=min(ans,min(calc(i,2*j+3*k),calc(i+2*j,3*k)));
						ans=min(ans,min(calc(i+3*k,2*j),calc(i+2*j+3*k,0)));
					}
				}
		cout<<ans<<endl;
	}
	return 0;
}