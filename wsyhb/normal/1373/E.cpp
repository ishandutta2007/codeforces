#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
typedef vector<int> num;
num ans,val;
bool operator < (num x,num y)
{
	if(y[0]==-1) return true;
	if(x[0]==-1) return false;
	if(x.size()<y.size()) return true;
	if(x.size()>y.size()) return false;
	int n=x.size();
	for(int i=n-1;i>=0;i--)
	{
		if(x[i]<y[i]) return true;
		if(x[i]>y[i]) return false;
	}
	return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		ans.clear();
		ans.push_back(-1);
		for(int i=1;i<=n/9;i++)
		{
			int x=9*i;
			for(int l=0;l<=k;l++)
			{
				int r=k-l;
				int now=n;
				now-=x*(l+1); 
				for(int j=0;j<=l;j++) now+=j;
				for(int j=0;j<r;j++) now-=j;
				now-=r;
				if(now<0||now%(k+1)!=0) continue;
				now/=k+1;
				val.clear();
				val.push_back(9-l);
				for(int j=2;j<=i;j++) val.push_back(9);
				if(now>=8)
				{
					now-=8;
					val.push_back(8);
				}
				while(now>=9)
				{
					now-=9;
					val.push_back(9);
				}
				if(now) val.push_back(now);
				ans=min(ans,val);
			}
		}
		for(int i=0;i<=9;i++)
		{
			bool flag=false;
			for(int j=0;j<=k;j++)
				if((i+j)%10==9)
				{
					flag=true;
					break;
				}
			if(flag) continue;
			int now=n;
			for(int j=0;j<=k;j++) now-=i+j;
			if(now<0||now%(k+1)!=0) continue;
			now/=k+1;
			val.clear();
			val.push_back(i);
			while(now>=9)
			{
				now-=9;
				val.push_back(9);
			}
			if(now) val.push_back(now);
			ans=min(ans,val);
		}
		for(int i=int(ans.size())-1;i>=0;i--) printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}