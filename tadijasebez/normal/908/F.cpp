#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
const int N=300050;
const int inf=1e9+7;
int min(int a, int b){ return a>b?b:a;}
int abs(int x){ return x>0?x:-x;}
int min(int a, int b, int c, int d){ return min(min(a,b),min(c,d));}
int max(int a, int b){ return a>b?a:b;}
int x[N];
ll sol;
vector<int> Green,Red,Blue;
char t[N];
bool vis[3];
int cnt;
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) 
	{
		scanf("%i %c",&x[i],&t[i]);
		if(t[i]=='G') Green.push_back(x[i]);
		if(t[i]=='R') Red.push_back(x[i]);
		if(t[i]=='B') Blue.push_back(x[i]);
		if(t[i]=='G' && !vis[0]) vis[0]=1,cnt++;
		if(t[i]=='R' && !vis[1]) vis[1]=1,cnt++;
		if(t[i]=='B' && !vis[2]) vis[2]=1,cnt++;
	}
	if(cnt==1)
	{
		printf("%i\n",x[n]-x[1]);
		return 0;
	}
	if(cnt==2)
	{
		if(!vis[0])
		{
			int taj=Blue.size()-1;
			sol+=Blue[taj]-Blue[0];
			taj=Red.size()-1;
			sol+=Red[taj]-Red[0];
			printf("%lld\n",sol);
			return 0;
		}
		if(!vis[1])
		{
			int taj=Green.size()-1;
			sol=Green[taj]-Green[0];
			if(Blue[0]<Green[0]) sol+=Green[0]-Blue[0];
			int taj1=Blue.size()-1;
			if(Blue[taj1]>Green[taj]) sol+=Blue[taj1]-Green[taj];
			for(i=0;i<Green.size()-1;i++)
			{
				int x1=lower_bound(Blue.begin(),Blue.end(),Green[i])-Blue.begin();
				if(x1!=Blue.size() && Blue[x1]<Green[i+1])
				{
					int x2=lower_bound(Blue.begin(),Blue.end(),Green[i+1])-Blue.begin();
					x2--;
					sol+=Green[i+1]-Green[i];
					int ans=Green[i+1]-Blue[x2];
					ans=max(ans,Blue[x1]-Green[i]);
					for(j=x1;j<x2;j++)
					{
						ans=max(ans,Blue[j+1]-Blue[j]);
					}
					sol-=ans;
				}
			}
			printf("%i\n",sol);
			return 0;
		}
		if(!vis[2])
		{
			int taj=Green.size()-1;
			sol=Green[taj]-Green[0];
			if(Red[0]<Green[0]) sol+=Green[0]-Red[0];
			int taj1=Red.size()-1;
			if(Red[taj1]>Green[taj]) sol+=Red[taj1]-Green[taj];
			for(i=0;i<Green.size()-1;i++)
			{
				int x1=lower_bound(Red.begin(),Red.end(),Green[i])-Red.begin();
				if(x1!=Red.size() && Red[x1]<Green[i+1])
				{
					int x2=lower_bound(Red.begin(),Red.end(),Green[i+1])-Red.begin();
					x2--;
					sol+=Green[i+1]-Green[i];
					int ans=Green[i+1]-Red[x2];
					ans=max(ans,Red[x1]-Green[i]);
					for(j=x1;j<x2;j++)
					{
						ans=max(ans,Red[j+1]-Red[j]);
					}
					sol-=ans;
				}
			}
			printf("%i\n",sol);
			return 0;
		}
	}
	int taj=Green.size()-1;
	sol=Green[taj]-Green[0];
	if(Blue[0]<Green[0]) sol+=Green[0]-Blue[0];
	if(Red[0]<Green[0]) sol+=Green[0]-Red[0];
	int taj1=Blue.size()-1;
	if(Blue[taj1]>Green[taj]) sol+=Blue[taj1]-Green[taj];
	int taj2=Red.size()-1;
	if(Red[taj2]>Green[taj]) sol+=Red[taj2]-Green[taj];
	for(i=0;i<Green.size()-1;i++)
	{
		ll temp=0;bool b=0,r=0;
		int x1=lower_bound(Blue.begin(),Blue.end(),Green[i])-Blue.begin();
		if(x1!=Blue.size() && Blue[x1]<Green[i+1])
		{
			int x2=lower_bound(Blue.begin(),Blue.end(),Green[i+1])-Blue.begin();
			x2--;
			sol+=Green[i+1]-Green[i];
			int ans=Green[i+1]-Blue[x2];
			ans=max(ans,Blue[x1]-Green[i]);
			for(j=x1;j<x2;j++)
			{
				ans=max(ans,Blue[j+1]-Blue[j]);
			}
			sol-=ans;
			b=1;
			temp+=ans;
		}
		x1=lower_bound(Red.begin(),Red.end(),Green[i])-Red.begin();
		if(x1!=Red.size() && Red[x1]<Green[i+1])
		{
			int x2=lower_bound(Red.begin(),Red.end(),Green[i+1])-Red.begin();
			x2--;
			sol+=Green[i+1]-Green[i];
			int ans=Green[i+1]-Red[x2];
			ans=max(ans,Red[x1]-Green[i]);
			for(j=x1;j<x2;j++)
			{
				ans=max(ans,Red[j+1]-Red[j]);
			}
			sol-=ans;
			r=1;
			temp+=ans;
		}
		if(r && b)
		{
			if(temp<Green[i+1]-Green[i])
			{
				sol-=Green[i+1]-Green[i];
				sol+=temp;
			}
		}
	}
	/*for(i=1;i<=n;i++)
	{
		if(t[i]=='R')
		{
			int ans=inf;
			int x1=lower_bound(Green.begin(),Green.end(),x[i])-Green.begin();
			if(x1==Green.size()) x1--;
			ans=min(ans,abs(Green[x1]-x[i]));
			int x2=x1;
			if(x1!=0) x2--; 
			ans=min(ans,abs(Green[x2]-x[i]));
			int x3=upper_bound(Red.begin(),Red.end(),x[i])-Red.begin();
			int x4;
			if(x3!=Red.size()) ans=min(ans,abs(Red[x3]-x[i]));
			if(Red[0]!=x[i]) x4=x3-2,ans=min(ans,abs(Red[x4]-x[i]));
			sol+=ans;
			//sol+=min(abs(Green[x1]-x[i]),abs(Green[x2]-x[i]),abs(Red[x3]-x[i]),abs(Red[x4]-x[i]));
		}
		if(t[i]=='B')
		{
			int ans=inf;
			int x1=lower_bound(Green.begin(),Green.end(),x[i])-Green.begin();
			if(x1==Green.size()) x1--;
			ans=min(ans,abs(Green[x1]-x[i]));
			int x2=x1;
			if(x1!=0) x2--; 
			ans=min(ans,abs(Green[x2]-x[i]));
			int x3=upper_bound(Blue.begin(),Blue.end(),x[i])-Blue.begin();
			int x4;
			if(x3!=Blue.size()) ans=min(ans,abs(Blue[x3]-x[i]));
			if(Blue[0]!=x[i]) x4=x3-2,ans=min(ans,abs(Blue[x4]-x[i]));
			sol+=ans;
			//int x1=lower_bound(Green.begin(),Green.end(),x[i])-Green.begin();
			//int x2=x1;if(x1!=0) x2--;
			//int x3=lower_bound(Blue.begin(),Blue.end(),x[i])-Blue.begin();
			//int x4=x3;if(x3!=0) x4--;
			//sol+=min(abs(Green[x1]-x[i]),abs(Green[x2]-x[i]),abs(Blue[x3]-x[i]),abs(Blue[x4]-x[i]));
		}
	}*/
	printf("%lld\n",sol);
	return 0;
}