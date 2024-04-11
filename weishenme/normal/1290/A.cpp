#include<bits/stdc++.h>
using namespace std;
const int N=3505;
int T,n,m,k,a[N];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&n,&m,&k);
		k=min(k,m-1);int t=m-k-1;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		int ans=0;
		for (int i=0;i<=k;i++){
			int sum=1e9;
			for (int j=0;j<=t;j++)sum=min(sum,max(a[i+j+1],a[n-(k-i)-(t-j)]));
			ans=max(ans,sum);
		}
		printf("%d\n",ans);
	}
}