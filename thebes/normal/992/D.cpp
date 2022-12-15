#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int arr[MN], n, k, i, j, nxt[MN];
long long prod, sum, ans;

int main(){
	for(scanf("%d%d",&n,&k),i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(i=n;i>=1;i--){
		if(arr[i]==1) nxt[i]=nxt[i+1]+1;
	}
	for(i=1;i<=n;i++){
		sum = 0; prod = 1;
		for(j=i;j<=n;j++){
			if(arr[j]!=1) prod*=arr[j],sum+=arr[j];
			else{
				if(prod%k==0&&sum<prod/k&&sum>=prod/k-nxt[j]) ans++;
				sum += nxt[j]; j+=nxt[j]-1; continue;
			}
			if(sum*k==prod) ans++;
			if(prod/(sum+n)>k) break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}