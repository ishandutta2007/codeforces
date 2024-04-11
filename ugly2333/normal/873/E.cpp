//??CF 873E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 3033;
pair<int,int> a[N];
int b[N];
vector<int> v[N];
int mn[N],mn1[N];
int ans[N];
bool ok(int x,int y,int z){
	return max(x,max(y,z))<=2*min(x,min(y,z));
}
int main()
{
	int n,i,j,t,mx12,mx23,mx34,mx34i,mx34j;
	cin>>n;
	for(i=1;i<=n;i=i+1){
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	a[n+1]=make_pair(0,n+1);
	for(i=1;i<=n;i=i+1)
		b[i]=a[i].first-a[i+1].first;
	mx12=0;
	for(i=1;i<=(n-i)/2*2;i=i+1)
		mx12=max(mx12,b[i]);
	mx23=0;
	for(i=1;i<=(n-i)/2*2;i=i+1)
		if(b[i]==mx12)
			for(j=i+(i+1)/2;j<=n&&j<=i+i*2&&2*(n-j)>=i&&2*(n-j)>=j-i;j=j+1)
				mx23=max(mx23,b[j]);
	for(i=1;i<=(n-i)/2*2;i=i+1)
		if(b[i]==mx12)
			for(j=i+(i+1)/2;j<=n&&j<=i+i*2&&2*(n-j)>=i&&2*(n-j)>=j-i;j=j+1)
				if(b[j]==mx23){
					v[j].push_back(i);
					t=min(i,j-i);
					if(!mn[j]||mn[j]>t)
						mn[j]=t,mn1[j]=i;
				}
	mx34=0;
	for(i=2;i<n;i=i+1){
		for(j=i+1;j<=n;j=j+1)
			if(ok(i-mn[i],mn[i],j-i))
				if(!mx34||mx34<b[j]){
					mx34=b[j];
					mx34i=i;
					mx34j=j;
				}
	}
	//cout<<mx12<<mx23<<mx34<<endl;
	for(i=1;i<=mn1[mx34i];i=i+1)
		ans[a[i].second]=1;
	for(;i<=mx34i;i=i+1)
		ans[a[i].second]=2;
	for(;i<=mx34j;i=i+1)
		ans[a[i].second]=3;
	for(;i<=n;i=i+1)
		ans[a[i].second]=-1;
	for(i=1;i<=n;i=i+1)
		cout<<ans[i]<<' ';
	return 0;
}
/*
11
5  4 7 5  2 7 8 5 7 8 8

3 -1 2 3 -1 2 1 3 2 1 1

3  3 2 3  3 2 1 3 2 1 1

*/