#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#include<stdlib.h>
using namespace std;

#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
#define DBG if(1)
#define NDBG if(0)

typedef long long ll;
typedef pair<int,int> pii;

const int MN = 200000 + 5;
const int TN = 1<<18;

int N;
int val[MN];
int son[MN], bro[MN];
ll dist[MN];
int C;
int st[MN],ed[MN];
int T[2*TN];
void update(int n){
	for(n+=TN;n>0;n>>=1){
		T[n]++;
	}
}
int getsum(int l,int r){
	int res=0;
	for(l+=TN, r+=TN;l<=r;l>>=1,r>>=1){
		if(l&1) res+=T[l++];
		if(!(r&1)) res+=T[r--];
	}
	return res;
}

struct QUERY{
	int type, idx;
	ll val;
}query[2*MN];

void dfs(int n){
	st[n]=C++;
	for(int p=son[n]; p!=-1; p=bro[p]){
		dist[p]+=dist[n];
		dfs(p);
	}
	ed[n]=C-1;
}

int ans[MN];

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&val[i]);
		son[i]=bro[i]=-1;
	}
	for(int i=1;i<N;i++){
		II(p)II(w); p--;
		bro[i] = son[p];
		son[p] = i;
		dist[i] = w;
	}
	dfs(0);
	for(int i=0;i<N;i++){
		query[2*i] = {0, i, dist[i]-val[i]};
		query[2*i+1] = {1, i, dist[i]};
	}
	sort(query, query+2*N, [](QUERY &A, QUERY &B){
		if(A.val!=B.val) return A.val<B.val;
		return A.type<B.type;
	});
	for(int i=0;i<2*N;i++){
		auto q = query[i];
		if(q.type==0){
			update(st[q.idx]);
		}
		else{
			ans[q.idx] = getsum(st[q.idx], ed[q.idx]);
		}
	}
	for(int i=0;i<N;i++) printf("%d ", ans[i] - 1);
	return 0;
}