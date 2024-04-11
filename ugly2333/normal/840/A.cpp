//CF 840A
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
int a[222222],ans[222222];
pair<int,int> b[222222];
int main()
{
	int n,i,x;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	for(i=1;i<=n;i=i+1){
		scanf("%d",&x);
		b[i]=make_pair(-x,i);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(i=1;i<=n;i=i+1){
		ans[b[i].second]=a[i];
	}
	for(i=1;i<=n;i=i+1)
		cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}