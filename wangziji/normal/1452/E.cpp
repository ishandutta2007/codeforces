#include <iostream>
#include <cstring>
using namespace std;
pair <int,int> a[2005];
pair <int,int> x;
int cf[2005],cfcf[2005];
inline int cal(pair <int,int> x,pair<int,int> y)
{
	return max(min(x.second,y.second)-max(x.first,y.first)+1,0);
}
int main(int argc, char** argv) {
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
		cin >> a[i].first >> a[i].second;
	int ans=0;
	for(int i=1;i<=n-k+1;i++)
	{
		memset(cf,0,sizeof cf);
		memset(cfcf,0,sizeof cfcf);
		x={i,i+k-1};
	//	cout << x.first << " " << x.second << "\n";
		for(int j=1;j<=m;j++)
		{
			int qwq=cal(a[j],x);
			cf[1]+=qwq;
			int l1=a[j].first-k+qwq+1,r1=a[j].first;
			int l2=a[j].second-k+2,r2=a[j].second-qwq+1;
		//	cout << qwq << " " << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
			if(l1<=0) cf[1]+=1-l1,l1=1;
			if(l2<=0) cf[1]-=1-l2,l2=1;
		//	if(r1<=l2)
		//	{
				++cfcf[l1],--cfcf[r1+1];
				--cfcf[l2],++cfcf[r2+1];
		//	}
		}
		for(int j=1;j<=n;j++) cfcf[j]+=cfcf[j-1],cf[j]+=cfcf[j];
		for(int j=1;j<=n;j++) cf[j]+=cf[j-1],ans=max(ans,cf[j]);
	/*	for(int j=1;j<=n;j++)
		{
			cout << cf[j] << " ";
		}
		puts("");*/
	}
	cout << ans;
	return 0;
}