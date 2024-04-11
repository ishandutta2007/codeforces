#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int r[MN], fl[MN], N, i, arr[MN], tot, c;

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	for(tot=arr[N],i=N-1;i>=1;i--){
		if(tot<=arr[i]) fl[i+1]=1, tot=arr[i]-tot;
		else r[i]=1, tot-=arr[i];
	}
	for(i=1;i<=N;i++){
		c ^= fl[i];
		printf("%c",(c^r[i])?'-':'+');
	}
	return 0;
}