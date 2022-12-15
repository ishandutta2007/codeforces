#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 3e5+5;
vi elem[MN], go[MN];
int T, N, i, j, arr[MN], ans[MN], vs[MN];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(i=1;i<=N;i++){
			scanf("%d",&arr[i]);
			go[i].clear();
			elem[arr[i]].pb(i);
		}
		for(i=1;i<=N;i++){
			if(vs[arr[i]]) continue;
			vs[arr[i]] = 1;
			int lo = 1, hi = N;
			while(lo<hi){
				int mid = (lo+hi)>>1;
				int lst = 0;
				for(auto v : elem[arr[i]]){
					if(v-mid<=lst){
						lst = v;
					}
				}
				if(lst+mid-1>=N) hi=mid;
				else lo=mid+1;
			}
			go[lo].pb(arr[i]);
		}
		ans[0] = 1<<30;
		for(i=1;i<=N;i++){
			ans[i] = ans[i-1];
			for(auto v : go[i])
				ans[i] = min(ans[i], v);
			if(ans[i]==1<<30) printf("-1 ");
			else printf("%d ",ans[i]);
		}
		printf("\n");
		for(i=1;i<=N;i++){
			vs[arr[i]] = 0;
			elem[arr[i]].clear();
		}
	}
	return 0;
}