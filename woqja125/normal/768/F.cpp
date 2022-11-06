#include<stdio.h>
const int MOD = 1000000007;
int fact[100001];
int fr[100001];
int pow(int x, int p){
	int re = 1, d = x;
	while(p){
		if(p%2 == 1) re = 1ll*re*d%MOD;
		p/=2;
		d = 1ll*d*d%MOD;
	}
	return re;
}
int re(int x){ return pow(x, MOD-2); }
int C(int n, int r){ if(n < r) return 0; return 1ll*fact[n]*fr[r]%MOD*fr[n-r]%MOD; }
int H(int n, int r){ return C(n+r-1, r); }

int main(){
	int f, w, h, all=0, pa=0;
	scanf("%d%d%d", &f, &w, &h); h++;
	if(w==0){
		printf("1");
		return 0;
	}
	if(f==0){
		if(h > w) printf("0");
		else printf("1");
		return 0;
	}
	fact[0] = 1;
	for(int i=1; i<=100000; i++) fact[i] = 1ll*fact[i-1]*i%MOD;
	for(int i=0; i<=100000; i++) fr[i] = re(fact[i]);
	for(int i=1; i<=f; i++){
		// i == j
		if(i <= f && i <= w){
			all = (all + 2ll*C(f-1, i-1)*C(w-1, i-1)%MOD)%MOD;
			if(w-1ll*i*h >= 0) pa = (pa + 2ll*C(f-1, i-1)*H(i, w-i*h)%MOD) % MOD;
		}
		// i == j+1
		if(i <= f && i-1 <= w && i-1 != 0){
			all = (all + 1ll*C(f-1, i-1)*C(w-1, i-2)%MOD)%MOD;
			if(w-(i-1ll)*h >= 0) pa = (pa + 1ll*C(f-1, i-1)*H(i-1, w-(i-1)*h)%MOD) % MOD;
		}
		// i == j-1
		if(i <= f && i+1 <= w){
			all = (all + 1ll*C(f-1, i-1)*C(w-1, i)%MOD)%MOD;
			if(w-(i+1ll)*h >= 0) pa = (pa + 1ll*C(f-1, i-1)*H(i+1, w-(i+1)*h)%MOD) % MOD;
		}
	}
	printf("%d", (int)(1ll*pa*re(all)%MOD));
	return 0;
}