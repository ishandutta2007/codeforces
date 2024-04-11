#include<bits/stdc++.h>
using namespace std;
const int N=1005;
pair<int,int>a[N],b[N]; 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].first,&a[i].second);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&b[i].first,&b[i].second);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	printf("%d %d\n",a[1].first+b[n].first,a[1].second+b[n].second);
	return 0;
}