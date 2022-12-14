//*

#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
#define MN 2000

int N;
int A[MN][MN];
long long S1[2*MN],S2[2*MN];

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	int i,j,x1,x2,y1,y2;
	long long v1,v2;
	for(i=0;i<N;i++)for(j=0;j<N;j++)scanf("%d",&A[i][j]);
	for(i=0;i<N;i++)for(j=0;j<N;j++){
		S1[i+j]+=A[i][j],S2[i-j+N]+=A[i][j];
	}
	v1=-1;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if((i+j)&1)continue;
			if(v1<S1[i+j]+S2[i-j+N]-A[i][j]){
				v1=S1[i+j]+S2[i-j+N]-A[i][j];
				x1=i+1,y1=j+1;
			}
		}
	}
	v2=-1;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(!((i+j)&1))continue;
			if(v2<S1[i+j]+S2[i-j+N]-A[i][j]){
				v2=S1[i+j]+S2[i-j+N]-A[i][j];
				x2=i+1,y2=j+1;
			}
		}
	}
	printf("%lld\n%d %d %d %d",v1+v2,x1,y1,x2,y2);
	return 0;
}

//*/