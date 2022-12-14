//*/
#include<stdio.h>
#include<algorithm>
//#pragma warning(disable:4996)
#define MN 500

using namespace std;


int N,A[MN][MN],P[MN],V[MN],C;
int ind[MN][MN],L[MN],val[MN][MN];
char inp[MN+1];

void dfs(int n){
	V[n]=1;
	int i;
	ind[C][L[C]]=n;
	val[C][L[C]]=P[n];
	L[C]++;
	for(i=0;i<N;i++){
		if(!A[n][i] || V[i])continue;
		dfs(i);
	}
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i,j;
	scanf("%d",&N);
	for(i=0;i<N;i++)scanf("%d",&P[i]),P[i]--;
	for(i=0;i<N;i++){
		scanf("%s",inp);
		for(j=0;j<N;j++)A[i][j]=inp[j]-'0';
	}
	for(i=0;i<N;i++){
		if(V[i])continue;
		dfs(i);
		C++;
	}
	for(i=0;i<C;i++){
		sort(ind[i],ind[i]+L[i]);
		sort(val[i],val[i]+L[i]);
		for(j=0;j<L[i];j++)P[ind[i][j]]=val[i][j]+1;
	}
	for(i=0;i<N;i++)printf("%d ",P[i]);
	return 0;
}
//*/