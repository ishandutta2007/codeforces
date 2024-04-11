#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll c[4004], v[4004], d[4004], q[4004], N, i, j, k, cnt;
vector<int> ans;

int main(){
	for(scanf("%lld",&N),i=1;i<=N;i++)
		scanf("%lld%lld%lld",&v[i],&d[i],&c[i]);
	for(i=1;i<=N;i++){
		if(!q[i]){
			ans.push_back(i);
			for(j=i+1;j<=N&&v[i]>0;j++){
				if(q[j]) continue;
				c[j] -= v[i]; v[i]--;
			}
			for(j=i+1;j<=N;j++){
				if(c[j]<0&&!q[j]){
					q[j] = 1;
					for(k=j+1;k<=N;k++)
						if(!q[k]) c[k] -= d[j];
				}
			}
		}
	}
	printf("%d\n",ans.size());
	for(int v : ans) printf("%d ",v);
	return 0;
}