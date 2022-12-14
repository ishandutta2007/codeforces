//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#include<set>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define MN 200000
#define TN 262144
using namespace std;

int N;
int A[MN];
int p[MN];
int T[2*TN];
int ans[MN+1];

set<int> pos;

bool cmp(int a,int b){
	return A[a]<A[b];
}

void update(int n,int v){
	n+=TN;
	T[n]=v;
	for(n>>=1;n;n>>=1){
		T[n]=max(T[2*n],T[2*n+1]);
	}
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=0;i<N;i++)p[i]=i;
	sort(p,p+N,cmp);
	pos.insert(N),pos.insert(-1);
	update(N,N);
	int it=N;
	for(int i=0;i<N;i++){
		int v=p[i];
		pos.insert(v);
		auto iter=pos.find(v);
		iter--;
		update(v,v-(*iter)-1);
		iter++;iter++;
		update((*iter),(*iter)-v-1);
		for(int k=it;k>T[1];k--){
			ans[k]=A[v];
		}
		it=T[1];
	}
	for(int i=1;i<=N;i++)printf("%d ",ans[i]);
	return 0;
}
//*