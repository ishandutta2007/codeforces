#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int f[MN], a[MN], b[MN], i, j, N, M, ans;

int main(){
	for(scanf("%d%d",&N,&M),i=0;i<N;i++){
		scanf("%d",&a[i]);
		if(i) a[i-1] = a[i]-a[i-1];
	}
	for(i=0;i<M;i++){
		scanf("%d",&b[i]);
		b[i-1] = b[i]-b[i-1];
	}
	N--; M--; i=1; j=0;
	while(i < M){
		if(b[i]==b[j]){f[i]=j+1; i++;j++;}
		else if(j>0) j = f[j-1];
		else{f[i]=0; i++;}
	}
	i=0;j=0;
	while(i < N){
		if(a[i] == b[j]){
			i++; j++;
			if(j == M){
				ans++; j = f[M-1];
			}
		}
		else if(j > 0) j=f[j-1];
		else i++;
	}
	printf("%d\n",(M)?ans:N+1);
	return 0;
}