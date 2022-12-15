#include <bits/stdc++.h>
using namespace std;

const int MM=105,MN=1e6+6,mod=1e9+7;
int mat[MM], b[MM], tmp[MM], N, M, K, i, j;
int orig[MM], wtf[MN];
void mul(bool wtf){
	memset(tmp,0,sizeof(tmp));
	for(int i=0;i<K;i++){
		for(int j=0;j<K;j++)
			tmp[(i+j)%K]=(tmp[(i+j)%K]+1LL*mat[i]*mat[j])%mod;
	}
	copy(tmp,tmp+MM,mat);
	if(!wtf) return;
	memset(tmp,0,sizeof(tmp));
	for(int i=0;i<K;i++){
		for(int j=0;j<K;j++)
			tmp[(i+j)%K]=(tmp[(i+j)%K]+1LL*mat[i]*b[j])%mod;
	}
	copy(tmp,tmp+MM,mat);
}

void exp(int P){
	for(int i=30;i>=0;i--)
		mul(P&(1<<i));
}

int main(){
	for(scanf("%d%d%d",&N,&M,&K),i=1;i<=N;i++){
		int x; scanf("%d",&x);
		orig[x%K]++; 
	}
	for(i=1;i<=N;i++){
		int x; scanf("%d",&x);
		b[x%K]++; wtf[i]=x%K;
	}
	mat[0]=1; exp(M-2);
	memset(tmp,0,sizeof(tmp));
	for(int i=0;i<K;i++){
		for(int j=0;j<K;j++)
			tmp[(i+j)%K]=(tmp[(i+j)%K]+1LL*mat[i]*orig[j])%mod;
	}
	int ans = 0;
	for(i=1;i<=N;i++){
		int x; scanf("%d",&x);
		ans = (ans+tmp[(-wtf[i]-x+4LL*K)%K])%mod;
	}
	printf("%d\n",ans);
	return 0;
}