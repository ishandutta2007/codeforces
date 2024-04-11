//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define MN 200000
using namespace std;

int N,leaf;
int son[MN],bro[MN];

int Max(int n);
int Min(int n);

int Max(int n){
	int p=son[n],v=1e9;
	if(p==-1)return 1;
	while(p!=-1){
		int t=Min(p);
		if(v>t)v=t;
		p=bro[p];
	}
	return v;
}

int Min(int n){
	int p=son[n],v=0;
	if(p==-1)return 1;
	while(p!=-1){
		int t=Max(p);
		v+=t;
		p=bro[p];
	}
	return v;
}

void dfs(int n){
	for(int p=son[n];p!=-1;p=bro[p]){
		dfs(p);
	}
	if(son[n]==-1)leaf++;
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<N;i++)son[i]=bro[i]=-1;
	for(int i=0;i<N-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);--a,--b;
		bro[b]=son[a];
		son[a]=b;
	}
	dfs(0);
	printf("%d %d",leaf-Max(0)+1,Min(0));
	return 0;
}
//*/