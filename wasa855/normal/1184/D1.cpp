#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans; return ans;
}
#define N 205
 
signed main()
{
	int n,k,m,t;
	cin>>n>>k>>m>>t;
	int u,v;
	int sum=n;
	for(int i=1;i<=t;i++)
	{
		scanf("%d %d",&u,&v);
		if(u==0)
		{
			if(v<k)
			{
				sum=sum-v;
//				cout<<"**"<<sum<<"\n";
				k-=v;
			}
			else
			{
				sum=v;
			}
		}
		else
		{
			sum++;
			if(v<=k) k++;
		}
		printf("%d %d\n",sum,k);
	}
	return 0;
}
//efqfe