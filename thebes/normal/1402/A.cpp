#include <bits/stdc++.h>
using namespace std;

const int MN = 1005;
int T, N, i, x, arr[MN];
map<int,int> mp;

int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d",&N);
		mp.clear();
		for(i=1;i<=N;i++){
			scanf("%d",&x);
			mp[x]++;
		}
		int ans = 0, f1 = 1, f2 = 1;
		for(i=0;i<=N;i++){
			if(mp[i]==1&&f2){
				f2 = 0;
				ans += i;
			}
			else if(mp[i]==0&&f1){
				if(f2) ans += i, f2 = 0;
				ans += i, f1 = 0;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}