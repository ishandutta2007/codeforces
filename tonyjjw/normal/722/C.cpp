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

const int MN = 100000 + 1;
const int TN = 131072;
const ll INF = 1e15;

struct DATA{
	ll pre, post, all, sum;
}T[2*TN];

void relax(int n){
	auto &l = T[2*n];
	auto &r = T[2*n+1];
	T[n].pre = max(l.pre, l.sum + r.pre);
	T[n].post = max(r.post, r.sum + l.post);
	T[n].all = max(max(l.all, r.all), l.post + r.pre);
	T[n].sum = l.sum + r.sum;
	if(T[n].sum < -INF) T[n].sum = -INF;
}

int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		II(a);
		T[TN+i].pre = T[TN+i].post = T[TN+i].all = T[TN+i].sum = a;
	}
	for(int i=TN-1;i>0;i--){
		relax(i);
	}
	for(int i=0;i<N;i++){
		II(idx); idx += TN-1;
		T[idx].pre = T[idx].post = T[idx].all = 0;
		T[idx].sum = -INF;
		for(idx/=2; idx>0; idx/=2){
			relax(idx);
		}
		printf("%lld\n", T[1].all);
	}
	return 0;
}