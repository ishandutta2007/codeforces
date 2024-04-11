//*

#include<stdio.h>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
#define MN 2000

using namespace std;

vector<int> G[MN];

int N,NN;
int A[MN][MN],B[MN][MN],p[MN];

int par(int n){
	return p[n]==n?n:p[n]=par(p[n]);
}

struct DATA{
	int a,b,c;
	bool operator <(DATA A)const{
		return c<A.c;
	}
}D[MN*MN/2];

int main(){
	int i,j,k;
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	for(i=0;i<N;i++)p[i]=i,G[i].push_back(i);
	for(i=0;i<N;i++)for(j=0;j<N;j++)scanf("%d",&A[i][j]);
	for(i=0;i<N;i++)if(A[i][i])break;
	if(i<N){
		puts("NO");
		return 0;
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(A[i][j]!=A[j][i])break;
		}
		if(j<N)break;
	}
	if(i<N){
		puts("NO");
		return 0;
	}
	for(i=0;i<N;i++)for(j=0;j<i;j++){
		D[NN].a=i,D[NN].b=j,D[NN].c=A[i][j];
		NN++;
	}
	sort(D,D+NN);
	for(i=0;i<NN;i++){
		int p1=par(D[i].a),p2=par(D[i].b);
		if(p1==p2){
			if(B[D[i].a][D[i].b]!=D[i].c){
				puts("NO");
				return 0;
			}
			continue;
		}
		p[p2]=p1;
		if(D[i].c<=0){
			puts("NO");
			return 0;
		}
		B[D[i].a][D[i].b]=B[D[i].b][D[i].a]=D[i].c;
		for(j=0;j<G[p1].size();j++)for(k=0;k<G[p2].size();k++){
			B[G[p2][k]][G[p1][j]]=B[G[p1][j]][G[p2][k]]=B[G[p1][j]][D[i].a]+D[i].c+B[D[i].b][G[p2][k]];
		}
		while(!G[p2].empty()){
			G[p1].push_back(G[p2][G[p2].size()-1]);
			G[p2].pop_back();
		}
	}
	puts("YES");
	return 0;
}

//*/