//CF 91B
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
const int N = 111111;
int n,a[N],ans[N];
pair<int,int> p[N];
int main()
{
	int i,x;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		p[i]=make_pair(a[i],i);
	}
	sort(p+1,p+n+1);
	x=0;
	for(i=1;i<=n;i=i+1){
		if(p[i].second>x)
			x=p[i].second;
		ans[p[i].second]=x-p[i].second-1;
	}
	for(i=1;i<=n;i=i+1)
		cout<<ans[i]<<' ';
	return 0;
}