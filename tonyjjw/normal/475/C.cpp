//*

#include<stdio.h>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
#define MN 1000
#define INF 1e9

using namespace std;

int N,M;
char map[MN][MN+1];
int A[MN][MN],S[MN][MN],V[MN][MN];

inline int s(int i,int j,int k,int l){
	int v11,v12,v21;
	v11=(i&&j)?S[i-1][j-1]:0;
	v12=i?S[i-1][l]:0;
	v21=j?S[k][j-1]:0;
	return S[k][l]-v12-v21+v11;
}

int sx,sy;

bool chk(int R,int C){
	int i,j,k;
	for(i=0;i<N;i++)for(j=0;j<M;j++)V[i][j]=0;
	for(i=sx;i<sx+R;i++)for(j=sy;j<sy+C;j++)V[i][j]=1;
	i=sx,j=sy;
	for(;;){
		if(s(i,j,i+R-1,j+C-1)!=R*C)return false;
		if(i+R<N && A[i+R][j]){
			for(k=j;k<j+C;k++)V[i+R][k]=1;
			i++;
		}
		else if(j+C<M && A[i][j+C]){
			for(k=i;k<i+R;k++)V[k][j+C]=1;
			j++;
		}
		else{
			break;
		}
	}
	for(i=0;i<N;i++)for(j=0;j<M;j++)if(A[i][j]^V[i][j])return false;
	return true;
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&M);
	int i,j,R,C,e,ans=INF;
	for(i=0;i<N;i++)scanf("%s",map[i]);
	for(i=0;i<N;i++)for(j=0;j<M;j++)if(map[i][j]=='X')A[i][j]=S[i][j]=1;
	for(i=0;i<N;i++)for(j=1;j<M;j++)S[i][j]+=S[i][j-1];
	for(i=1;i<N;i++)for(j=0;j<M;j++)S[i][j]+=S[i-1][j];
	for(i=0;i<N;i++){
		for(j=0;j<M;j++)if(A[i][j])break;
		if(j<M)break;
	}
	sx=i,sy=j;

	for(i=sx;i<N;i++)if(!A[i][sy])break;
	R=i-sx;
	for(j=sy;j<M;j++)if(!A[sx][j])break;
	e=j;
	if(i==N){
		C=e-sy;
	}
	else{
		for(j=sy;j<e;j++)if(A[sx+R][j])break;
		if(j<e)C=e-j;
		else	C=e-sy;
	}
	if(chk(R,C)){
		if(ans>R*C)ans=R*C;
	}
	if(chk(1,C) && ans>C)ans=C;
	if(chk(R,1) && ans>R)ans=R;

	for(j=sy;j<M;j++)if(!A[sx][j])break;
	C=j-sy;
	for(i=sx;i<N;i++)if(!A[i][sy])break;
	e=i;
	if(j==M){
		R=e-sx;
	}
	else{
		for(i=sx;i<e;i++)if(A[i][sy+C])break;
		if(i<e)R=e-i;
		else	R=e-sx;
	}
	if(chk(R,C)){
		if(ans>R*C)ans=R*C;
	}
	if(chk(1,C) && ans>C)ans=C;
	if(chk(R,1) && ans>R)ans=R;
	if(ans==INF){
		printf("-1");
		return 0;
	}
	printf("%d",ans);

	return 0;
}

//*/