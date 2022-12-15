#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second

const int MN = 2e5+5;
int N, i, x[MN], y[MN], w[MN], vs[MN], cur[MN];
vi id[MN], ans;

inline void apply(int i,int c){
	cur[x[i]] -= c;
	cur[y[i]] += c;
	cur[w[i]] += c;
}

bool go(int n){
	for(auto v : id[n]){
		if(vs[v]) continue;
		apply(v,1);
		if(cur[y[v]]<=9&&cur[w[v]]<=9){
			ans.push_back(v);
			vs[v] = 1;
			go(x[v]);
			return 1;
		}
		else apply(v,-1);
	}
	return 0;
}

int main(){
	scanf("%d",&N);
	for(i=1;i<=4*N;i++){
		scanf("%d%d%d",&x[i],&y[i],&w[i]);
		id[y[i]].push_back(i);
		id[w[i]].push_back(i);
	}
	for(i=1;i<=N;i++)
		cur[i] = 4;
	for(i=1;i<=N;i++){
		while(go(i));
	}
	if(ans.size()==4*N){
		printf("YES\n");
		for(auto v : ans)
			printf("%d ",v);
		printf("\n");
	}
	else printf("NO\n");
	return 0;
}