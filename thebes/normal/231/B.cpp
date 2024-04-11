#include <bits/stdc++.h>
using namespace std;
int n, k, l, i, tot, arr[105];
int main(){
	scanf("%d%d%d",&n,&k,&l);
	for(i=1;i<=n;i++) arr[i]=1,k-=(i%2)?arr[i]:-arr[i];
	for(i=1;i<=n;i++){
		if(k==0) continue;
		if(k>0&&i%2){
			int d = min(l-1,k);
			arr[i] += d; k-=d;
		}
		else if(k<0&&i%2==0){
			int d = max(-l+1,k);
			arr[i] -= d; k-=d;
		}
	}
	if(k) printf("-1\n");
	else{
		for(i=1;i<=n;i++)
			printf("%d ",arr[i]);
	}
	return 0;
}