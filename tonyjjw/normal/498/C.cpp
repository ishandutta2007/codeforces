//*
#include<stdio.h>
#include<set>
#include<vector>
#pragma warning(disable:4996)
#define MN 200

using namespace std;

int N,M,ans,n;
int A[MN],F[MN+2][MN+2],pc,p[MN+2],V[MN+2];
vector<int> C[MN];
set<int> S;

int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}

int num(int n,int b){
	int cnt=0;
	while(n%b==0){
		n/=b,cnt++;
	}
	return cnt;
}

bool dfs(int n,int c){
	V[n]=1;
	p[c]=n;
	if(n==N+1){
		pc=c;
		return true;
	}
	int i;
	for(i=0;i<=N+1;i++){
		if(!V[i] && F[n][i]>0 && dfs(i,c+1))return true;
	}
	return false;
}

void calc(int v){
	int i,j;
	for(i=0;i<=N+1;i++)for(j=0;j<=N+1;j++)F[i][j]=0;
	for(i=1;i<=n;i++){
		F[0][i]=num(A[2*(i-1)],v);
	}
	for(i=n+1;i<=N;i++){
		F[i][N+1]=num(A[2*(i-n)-1],v);
	}
	for(i=0;i<N;i+=2){
		for(j=0;j<C[i].size();j++){
			int k=C[i][j]/2+n+1;
			F[i/2+1][k]=100;
		}
	}
	for(i=0;i<=N+1;i++)V[i]=0;
	while(dfs(0,0)){
		int f=100;
		for(i=0;i<pc;i++){
			if(f>F[p[i]][p[i+1]])f=F[p[i]][p[i+1]];
		}
		for(i=0;i<pc;i++){
			F[p[i]][p[i+1]]-=f;
			F[p[i+1]][p[i]]+=f;
		}
		ans+=f;
		for(i=0;i<=N+1;i++)V[i]=0;
	}
}

vector<int> G;

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i,j,a,b;
	scanf("%d%d",&N,&M);
	n=(N+1)/2;
	for(i=0;i<N;i++)scanf("%d",&A[i]);
	for(i=0;i<M;i++){
		scanf("%d%d",&a,&b),--a,--b;
		C[a].push_back(b),C[b].push_back(a);
		G.push_back(gcd(A[a],A[b]));
	}
	for(i=0;i<M;i++){
		int g=G[i];
		for(j=2;j*j<=g;j++){
			if(g%j==0){
				while(g%j==0)g/=j;
				if(S.find(j)==S.end())S.insert(j);
			}
		}
		if(g!=1 && S.find(g)==S.end())S.insert(g);
	}
	set<int>::iterator it;
	for(it=S.begin();it!=S.end();it++){
		calc(*it);
	}
	printf("%d",ans);
	return 0;
}
//*/