#include <bits/stdc++.h>
using namespace std;

int N, K, arr[100005], i;
void cmp(int s, int e){
	if(K && s+1 < e){
		K -= 2; int m = (s+e)/2;
		swap(arr[m], arr[m+1]);
		cmp(s,m); cmp(m,e);
	}
}

int main(){
	for(scanf("%d%d",&N,&K),i=1;i<=N;i++)
		arr[i] = i;
	K--; cmp(0,N);
	if(K) printf("-1\n");
	else{for(i=1;i<=N;i++) printf("%d ",arr[i]);}
	return 0;
}