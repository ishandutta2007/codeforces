#include <bits/stdc++.h>
using namespace std;

const int MN = 1e4+4;
int freq[MN], cnt[1<<15], N, K, i, j, x;
long long wtf;

int main(){
	for(i=1;i<(1<<15);i++)
		cnt[i]=cnt[i-(i&-i)]+1;
	for(scanf("%d%d",&N,&K),i=1;i<=N;i++){
		scanf("%d",&x);
		freq[x] ++;
	}
	for(i=0;i<MN;i++){
		for(j=0;j<i;j++){
			if(cnt[i^j]==K)
				wtf += 1LL*freq[i]*freq[j];
		}
		if(!K) wtf+=1LL*freq[i]*(freq[i]-1)/2;
	}
	printf("%lld\n",wtf);
	return 0;
}