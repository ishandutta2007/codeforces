#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
const LL INF=1e18;
const int maxn=107;

LL sft[maxn+7];

int pw(LL t){
	if (t==1) return 1;
	return pw(t>>1)+1;
}

void fd(LL v){
	printf("%lld ",v);
	if (v==1) return; 
	int sg=pw(v);
	LL s=1;
	for (int i=1;i<sg;++i){
		s*=2;
	}
	LL pos=(((v-s+sft[sg])%s+s)%s+s)>>1;
	fd(((pos-s/2-sft[sg-1])%(s/2)+(s/2))%(s/2)+s/2);
}

int main(){
	memset(sft,0,sizeof(sft));
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int tp;
		LL u,v;
		scanf("%d",&tp);
		if (tp==1){
			scanf("%lld%lld",&u,&v);
			int sg=pw(u);
			LL s=1;
			for (int i=1;i<sg;++i){
				s*=2;
			}
			sft[sg]=((sft[sg]+v)%s+s)%s; 
		}
		if (tp==2){
			scanf("%lld%lld",&u,&v);
			int sg=pw(u);
			LL s=1,stp;
			for (int i=1;i<sg;++i){
				s*=2;
			}
			stp=(v%s+s)%s;
			while (s<=2*INF){
				sft[sg]=((sft[sg]+stp)%s+s)%s;
				s*=2;
				stp*=2;
				sg++;
			}
		}
		if (tp==3){
			scanf("%lld",&v);
			fd(v);
			printf("\n");
		}
	}
	return 0;
}