#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> T3;
const int MN = 1e5+5; long long tot, ans[MN];
int N, M, Q, B, i, arr[MN], j, l, r, pre[MN];
tuple<int,int,int> q[MN]; int cnt[2000006];

int main(){
	scanf("%d%d%d",&N,&Q,&M);
	B = sqrt(N+0.0);
	for(i=1;i<=N;i++) scanf("%d",&arr[i]);
	for(i=1;i<=Q;i++){
		int x, y;
		scanf("%d%d",&x,&y); x--; y++;
		q[i] = {x, y, i};
	}
	sort(q+1, q+Q+1, [](T3 i,T3 j){
		if(get<0>(i)/B==get<0>(j)/B) return get<1>(i)<get<1>(j);
		else return get<0>(i)<get<0>(j);
	});
	for(i=1,j=0;i<=N;i++){
		j ^= arr[i]; pre[i]=j;
	}
	for(i=1;i<=Q;i++){
		int L=get<0>(q[i]), R=get<1>(q[i]);
		while(r<R){
			tot+=cnt[pre[r]^M];
			cnt[pre[r]]++; r++;
		}
		while(r>R){
			r--; cnt[pre[r]]--;
			tot-=cnt[pre[r]^M];
		}
		while(l<L){
			cnt[pre[l]]--;tot-=cnt[pre[l]^M]; 
			l++;
		}
		while(l>L){
			l--; tot+=cnt[pre[l]^M];
			cnt[pre[l]]++;
		}
		ans[get<2>(q[i])]=tot;
	}
	for(i=1;i<=Q;i++)
		printf("%lld\n",ans[i]);
	return 0;
}