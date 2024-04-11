//CF 761A
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
pair<int,pair<int,int> > a[100005];
#define xx first
#define yy second
int ans[100005];
int main()
{
	int n,l,r,i,p;
	cin>>n>>l>>r;
	for(i=1;i<=n;i=i+1)
		scanf("%d",&a[i].yy.xx);
	for(i=1;i<=n;i=i+1)
		scanf("%d",&a[i].xx);
	for(i=1;i<=n;i=i+1)
		a[i].yy.yy=i;
	sort(a+1,a+n+1);
	ans[a[1].yy.yy]=l;
	p=l-a[1].yy.xx;
	for(i=2;i<=n;i=i+1){
		ans[a[i].yy.yy]=max(l,a[i].yy.xx+p+1);
		p=ans[a[i].yy.yy]-a[i].yy.xx;
		if(ans[a[i].yy.yy]>r){
			cout<<-1<<endl;
			return 0;
		}
	}
	for(i=1;i<=n;i=i+1)
		printf("%d ",ans[i]);
	return 0;
}