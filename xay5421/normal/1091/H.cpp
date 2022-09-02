#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=200005;
int n,F,p[N];
bool ban[N];
void sieve(){
	ban[0]=ban[1]=1;
	rep(i,2,N-1){
		if(!ban[i]){
			p[++*p]=i;
		}
		for(int j=1;j<=*p&&i*p[j]<N;++j){
			ban[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
bitset<N>bs,f[105];
int sg[N];
int main(){
	sieve();
	rep(i,1,*p){
		bs.set(p[i]);
		rep(j,1,*p){
			if(1LL*p[i]*p[j]<N){
				bs.set(p[i]*p[j]);
			}else
				break;
		}
	}
	scanf("%d%d",&n,&F);
	bs.reset(F);
	f[0]=bs;
	rep(i,1,N-1){
		while(f[sg[i]][i])++sg[i];
		f[sg[i]]|=bs<<i;
	}
	int SG=0;
	rep(i,1,n){
		int k1,k2,k3;
		scanf("%d%d%d",&k1,&k2,&k3);
		SG^=sg[k2-k1-1];
		SG^=sg[k3-k2-1];
	}
	if(SG){
		puts("Alice");
		puts("Bob");
	}
	else{
		puts("Bob");
		puts("Alice");
	}
	return 0;
}