#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,a[N],mx[N];
int main(){
	scanf("%d",&t);
	while(t--){
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx[i]=0;
		for(int i=2;i<=n-1;i++)if(a[i]>a[i-1]&&a[i]>a[i+1])mx[i]=1;
		for(int i=2;i<=n-1;i++)if(mx[i-1]&&mx[i+1])a[i]=max(a[i-1],a[i+1]),ans++,mx[i-1]=mx[i+1]=0;
		for(int i=1;i<=n;i++)if(mx[i])a[i]=max(a[i-1],a[i+1]),ans++;
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
		puts("");
	}
	return 0;
}