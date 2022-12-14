//*
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define MN 200000
#define MV 500000
using namespace std;

int N,Q;
int chk[MN];
int val[MV+1];
vector<int> pnum[MN];
typedef __int64 ll;

ll ans;

void dfs(int n,int i,int v,int c,ll &res){
	if(n==pnum[i].size()){
		if(v==1)return;
		res+=(c*val[v]);
		return;
	}
	dfs(n+1,i,v,c,res);
	dfs(n+1,i,v*pnum[i][n],c*(-1),res);
}

void upt(int n,int i,int v,int c){
	if(n==pnum[i].size()){
		val[v]+=c;
		return;
	}
	upt(n+1,i,v,c);
	upt(n+1,i,v*pnum[i][n],c);
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&Q);
	for(int i=0;i<N;i++){
		int a;
		scanf("%d",&a);
		for(int p=2;p*p<=a;p++){
			if(a%p==0){
				while(a%p==0)a/=p;
				pnum[i].push_back(p);
			}
		}
		if(a!=1){
			pnum[i].push_back(a);
		}
	}
	ll tot=0;
	for(int i=0;i<Q;i++){
		int n;
		scanf("%d",&n),n--;
		if(!chk[n]){
			tot++;
			dfs(0,n,1,-1,ans);
			upt(0,n,1,1);
		}
		else{
			tot--;
			upt(0,n,1,-1);
			dfs(0,n,1,1,ans);
		}
		chk[n]^=1;
		printf("%I64d\n",tot*(tot-1)/2-ans);
	}
	return 0;
}
//*