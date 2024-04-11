//*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

const int MN = 2000+1;
const int LIM = 5000+1;

int N;
int A[MN];
double P1[LIM];
double P2[LIM];

int main(){
	scanf("%d",&N);
	int lcnt=0;
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(i!=j){
		if(A[i]>A[j])lcnt++;
	}
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(i!=j){
		if(A[i]>A[j]){
			P1[A[i]-A[j]]+=1;
		}
	}
	for(int i=0;i<LIM;i++)P1[i]/=lcnt;
	for(int i=0;i<LIM;i++){
		for(int j=0;j<=i;j++){
			P2[i]+=P1[j]*P1[i-j];
		}
	}
	double ans=0;
	for(int i=0;i<LIM;i++){
		for(int j=i+1;j<LIM;j++){
			ans+=P2[i]*P1[j];
		}
	}
	printf("%.12lf\n",ans);
	return 0;
}

//*/