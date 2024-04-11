#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,r;
int a[maxn];
double ans[maxn];
int main(){
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		ans[i]=r;
		for(int j=1;j<i;j++)
			if(abs(a[i]-a[j])<=r+r){
				double x=(a[i]+a[j])/2.0;
				double y=ans[j]+sqrt(1.0*r*r-(x-a[i])*(x-a[i]));
				ans[i]=max(ans[i],sqrt(1.0*r*r-(x-a[j])*(x-a[j]))+y);
				//(x-x0)*(x-x0)+(y-y0)*(y-y0)=r*r
			}
	}
	for(int i=1;i<=n;i++)
		printf("%.6lf%c",ans[i],i==n? '\n':' ');
	return 0;
}