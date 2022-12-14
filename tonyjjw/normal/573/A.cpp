#include<stdio.h>
#pragma warning(disable:4996)
using namespace std;

int N,A[100000];

void reduce(int &a,int n){
	while(a%n==0)a/=n;
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=0;i<N;i++){
		reduce(A[i],2);
		reduce(A[i],3);
	}
	bool yes=true;
	for(int i=1;i<N;i++){
		if(A[i]!=A[0])yes=false;
	}
	puts(yes?"Yes":"No");
	return 0;
}