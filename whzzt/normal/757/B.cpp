#include "bits/stdc++.h"
using namespace std;
const int N=100005;
int n,a[N],c[N],ans[N],x,res;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),c[a[i]]++;
		x=max(x,a[i]);
	}
	for(int i=1;i<=x;i++)
		for(int j=1;j<=x/i;j++)
			ans[i]+=c[i*j];
	for(int i=2;i<=x;i++)res=max(res,ans[i]);
	printf("%d\n",max(res,1));
	return 0;
}