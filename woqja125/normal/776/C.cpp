#include<stdio.h>
#include<map>
using namespace std;
map<long long, int> S;
int main(){
	int n, t, k;
	long long s = 0, min = 0, max = 0;
	scanf("%d%d", &n, &k);
	S[0] = 1;
	long long ans = 0;
	for(int i=0; i<n; i++){
		scanf("%d", &t);
		s+=t;
		if(s < min) min = s;
		if(s > max) max = s;
		if(k==1){
			ans += S[s-1];
		} else if(k==-1){
			ans += S[s+1];
			ans += S[s-1];
		} else if(k>0){
			for(long long K=1; s-K >= min; K*=k){
				ans += S[s-K];
			}
		} else{
			for(long long K=1; s-K >= min; K*=1ll*k*k){
				ans += S[s-K];
			}
			for(long long K=k; s-K<=max; K*=1ll*k*k){
				ans += S[s-K];
			}
		}
		S[s]++;
	}
	printf("%lld", ans);
	return 0;
}