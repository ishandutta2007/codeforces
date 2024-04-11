#include <bits/stdc++.h>
using namespace std;

const int MN=2e5+5, MA=1e6+6;
int cnt[MA], N, S, Q, arr[MN], i, l, r; 
long long ans[MN];
struct qu{int l,r,id;}q[MN];

int main(){
	for(scanf("%d%d",&N,&Q),i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	S = sqrt(N+0.0);
	for(i=1;i<=Q;i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id = i;
	}
	sort(q+1, q+Q+1, [](qu i,qu j){return(i.l/S==j.l/S)?i.r<j.r:i.l<j.l;});
	long long tot=0; l=1;
	for(i=1;i<=Q;i++){
		while(r<q[i].r){
			r++; cnt[arr[r]]++;
			tot += (arr[r])*(2*cnt[arr[r]]-1);
		}
		while(r>q[i].r){
			tot -= (arr[r])*(2*cnt[arr[r]]-1);
			cnt[arr[r]]--; r--;
		}
		while(l<q[i].l){
			tot -= (arr[l])*(2*cnt[arr[l]]-1);
			cnt[arr[l]]--; l++;
		}
		while(l>q[i].l){
			l--; cnt[arr[l]]++;
			tot += (arr[l])*(2*cnt[arr[l]]-1);
		}
		ans[q[i].id] = tot;
	}
	for(i=1;i<=Q;i++)
		printf("%lld\n",ans[i]);
	return 0;
}