#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[10];
int b[100005];
int ans=0x3f3f3f3f;
int main(){
	int n,i,j,k;
	for(i=0;i<6;i++)scanf("%d",&a[i]);
	sort(a,a+6);
	a[6]=1e9;
	cin>>n;
	for(i=0;i<n;i++)scanf("%d",&b[i]);
	sort(b,b+n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<6;j++)
		{
			int l=b[i]-a[j],r=0;
			if(l>b[0]-a[0])continue;
			for(k=0;k<6;k++)r=max(r,*(lower_bound(b+1,b+n,l+a[k+1])-1)-a[k]);
			ans=min(ans,r-l);
		}
	}
	printf("%d\n",ans);
	return 0;
}