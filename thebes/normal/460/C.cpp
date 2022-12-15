#include <bits/stdc++.h>
using namespace std;

const int MN = 100005;
int dif[MN], N, M, W, i, arr[MN], lo, hi;

bool check(int h){
	int cnt=0,t=0; memset(dif,0,sizeof(dif));
	for(int i=1;i<=N&&cnt<=M;i++){
		t += dif[i];
		int x = max(0,h-arr[i]-t);
		cnt+=x; dif[i+1]+=x; dif[min(N+1,i+W)]-=x;
	}
	return (cnt<=M);
}

int main(){
	for(scanf("%d%d%d",&N,&M,&W),i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	lo = 1; hi = 1000000001+M;
	while(lo < hi){
		int m = (lo+hi)/2;
		if(check(m)) lo=m+1;
		else hi=m;
	}
	printf("%d\n",hi-1);
	return 0;
}