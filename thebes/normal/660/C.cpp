#include <bits/stdc++.h>
using namespace std;

int N, K, l, r, i, sol, p, arr[300005], a;

int main(){
	for(scanf("%d%d",&N,&K),i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	for(r=1;r<=N;r++){
		a += !arr[r];
		while(a>K)
			a -= !arr[++l];
		if(r-l > sol){
			sol = r-l; p=l+1;
		}
	}
	for(printf("%d\n",sol),i=1;i<=N;i++){
		if(i>=p&&i<=p+sol-1) printf("%d ",1);
		else printf("%d ",arr[i]);
	}
	return 0;
}