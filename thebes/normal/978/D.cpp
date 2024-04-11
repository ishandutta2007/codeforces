#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
long long arr[MN], N, i, j, k, x, d, cnt, ans=1<<30, flag;

int main(){
	for(scanf("%lld",&N),i=1;i<=N;i++)
		scanf("%lld",&arr[i]);
	if(N==1){printf("0\n"); return 0;}
	for(i=-1;i<=1;i++){
		for(j=-1;j<=1;j++){
			cnt = 0;
			if(i) cnt++;
			if(j) cnt++;
			d = (arr[2]+j)-(arr[1]+i);
			flag = false;
			for(k=3;k<=N;k++){
				if(arr[1]+i+(k-1)*d==arr[k]) continue;
				else if(abs(arr[1]+i+(k-1)*d-arr[k])==1) cnt++;
				else flag = 1;
			}
			if(!flag) ans=min(ans,cnt);
		}
	}
	printf("%d\n",(ans==1<<30)?-1:ans);
	return 0;
}