//*/
#include<stdio.h>
#include<vector>
#pragma warning(disable:4996)
#define MN 200000

using namespace std;

vector<int> E[MN];
int N,Q;
int V[MN],dep[MN],num[MN];
double ans;

struct ROAD{
	int a,b,l;
}A[MN-1];

void dfs(int n,int c){
	V[n]=1;
	dep[n]=c;
	int i;
	for(i=0;i<E[n].size();i++){
		if(V[E[n][i]])continue;
		dfs(E[n][i],c+1);
		num[n]+=num[E[n][i]];
	}
	num[n]++;
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i,j;
	scanf("%d",&N);
	for(i=0;i<N-1;i++){
		scanf("%d%d%d",&A[i].a,&A[i].b,&A[i].l),A[i].a--,A[i].b--;
		E[A[i].a].push_back(A[i].b);
		E[A[i].b].push_back(A[i].a);
	}
	dfs(0,0);
	for(i=0;i<N-1;i++){
		int p1,p2;
		if(dep[A[i].a]<dep[A[i].b])p1=A[i].a,p2=A[i].b;
		else{
			p1=A[i].b,p2=A[i].a;
		}
		ans+=(double)(N-num[p2])*num[p2]*A[i].l;
	}
	scanf("%d",&Q);
	for(i=0;i<Q;i++){
		int a,b;
		scanf("%d%d",&a,&b),--a;
		int p1,p2;
		if(dep[A[a].a]<dep[A[a].b])p1=A[a].a,p2=A[a].b;
		else{
			p1=A[a].b,p2=A[a].a;
		}
		ans-=(double)(N-num[p2])*num[p2]*(A[a].l-b);
		A[a].l=b;
		printf("%lf\n",6*ans/N/(N-1));
	}
	return 0;
}
//*/