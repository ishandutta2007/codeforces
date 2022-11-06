#include<stdio.h>
#include<queue>
int x[100001], y[100001];
int ne[200001];
int id[200001];
int c[200001];
const int MOD = 1000000007;
int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d%d", x+i, y+i);
		ne[x[i]] = y[i];
		id[y[i]]++;
	}
	for(int i=1; i<=2*n; i++) c[i] = 1;
	std::queue<int> Q;
	for(int i=1; i<=2*n; i++){
		if(id[i] == 0 && ne[i] != 0) Q.push(i);
	}
	long long ans = 1;
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		int p = ne[x];
		if(p==0){
			ans = ans * (c[x]) % MOD;
		}
		c[p] += c[x];
		id[p]--;
		if(id[p] == 0) Q.push(p);
	}
	for(int i=1; i<=2*n; i++){
		if(id[i] == 0) continue;
		int x = i;
		if(ne[x] == x) continue;
		do{
			id[x]--;
			x = ne[x];
		}while(x!=i);
		ans = ans * 2 % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}