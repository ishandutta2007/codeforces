//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define MN 1000000
using namespace std;

typedef tuple<int,int> SEG;

int N,M,p,S,ans[MN];
char inp[10];
vector<int> L[MN],R[MN];

bool dfs(int l,int r){
	if(l!=p)return true;
	int n=p;
	if(L[n].size()){
		int v=L[n][L[n].size()-1];
		p++;
		if(dfs(min(p,L[n][0]),v))return true;
	}
	ans[S++]=n+1;
	if(R[n].size()){
		int v=R[n][R[n].size()-1];
		p++;
		if(dfs(min(p,R[n][0]),max(r,v)))return true;
	}
	else{
		if(p<r){
			p++;
			if(dfs(p,r))return true;
		}
	}
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&M);
	int a,b;
	for(int i=0;i<M;i++){
		scanf("%d%d%s",&a,&b,inp),a--,b--;
		if(a>=b){
			puts("IMPOSSIBLE");
			return 0;
		}
		if(*inp=='L'){
			L[a].pb(b);
		}
		else{
			R[a].pb(b);
		}
	}
	for(int i=0;i<N;i++){
		sort(L[i].begin(),L[i].end());
		sort(R[i].begin(),R[i].end());
	}
	if(dfs(0,N-1)){
		puts("IMPOSSIBLE");
	}
	else{
		for(int i=0;i<N;i++){
			printf("%d ",ans[i]);
		}
	}
	return 0;
}
//*/