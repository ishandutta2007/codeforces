//*

#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
#define MN 100

int ans=-1;
int N,S;
int X[MN],Y[MN];

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i;
	scanf("%d%d",&N,&S);
	for(i=0;i<N;i++){
		scanf("%d%d",&X[i],&Y[i]);
		if(100*S>=100*X[i]+Y[i] && ans<(Y[i]?100-Y[i]:0)){
			ans=(Y[i]?100-Y[i]:0);
		}
	}
	printf("%d",ans);
	return 0;
}

//*/