#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#include<stdlib.h>
using namespace std;

#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
#define DBG if(1)
#define NDBG if(0)

typedef long long ll;
typedef pair<int,int> pii;

void my_assert(bool c){
	if(!c){
		puts("Impossible");
		exit(0);
	}
}

int findN(int v){
	for(int n=1;n*(n-1)<=2000000000;n++){
		if(n*(n-1)/2 == v) return n;
	}
	return -1;
}

const int MN = 200000 + 1;

int ans[MN];

int main(){
	II(a)II(b)II(c)II(d);
	if(a == 0 && b == 0 && c == 0 && d == 0){
		puts("0");
		return 0;
	}
	int zero, one;
	my_assert((zero = findN(a)) != -1);
	my_assert((one = findN(d)) != -1);
	if(a == 0 && b == 0 && c == 0){
		for(int i=0;i<one;i++) printf("1");
		return 0;
	}
	if(b==0 && c==0 && d==0){
		for(int i=0;i<zero;i++) printf("0");
		return 0;
	}
	my_assert(zero * one == b + c);
	int N = zero + one;
	for(int i = 0; i < N; i++){
		if(zero > c){
			zero--, ans[i]=0;
		}
		else{
			one--, ans[i]=1;
			c -= zero;
		}
		printf("%d",ans[i]);
	}
	return 0;
}