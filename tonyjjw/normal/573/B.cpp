#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
#define MN 100000

int N,A[MN];
int d1[MN],d2[MN];

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	d1[0]=1;
	for(int i=1;i<N;i++){
		d1[i]=min(d1[i-1]+1,A[i]);
	}
	d2[N-1]=1;
	for(int i=N-2;i>=0;i--){
		d2[i]=min(d2[i+1]+1,A[i]);
	}
	int ans=0;
	for(int i=0;i<N;i++)ans=max(ans,min(d1[i],d2[i]));
	printf("%d",ans);
	return 0;
}