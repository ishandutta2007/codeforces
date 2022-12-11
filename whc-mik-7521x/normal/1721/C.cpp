#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N],b[N],c[N],ans2[N],ans1[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)c[i]=upper_bound(a+1,a+n+1,b[i])-a-1-i;
		int o=n,k=n;
		for(int i=n;i>=1;i--){
			while(o>=1&&b[o]>=a[i]){
				if(c[o]==0)k=o;
				o--;
			}
			ans2[i]=b[k]-a[i];
			ans1[i]=(*lower_bound(b+1,b+n+1,a[i]))-a[i];
		}
		for(int i=1;i<=n;i++)printf("%d ",ans1[i]);
		puts("");
		for(int i=1;i<=n;i++)printf("%d ",ans2[i]);
		puts("");
	}
	return 0;
}