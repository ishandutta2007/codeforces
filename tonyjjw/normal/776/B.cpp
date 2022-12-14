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

const int MN = 100000 + 100;

int pp[MN];
vector<int> primes;
vector<int> factor[MN];

int main(){
	II(N); N++;
	for(int i=2;i<=N;i++)if(!pp[i]){
		primes.push_back(i);
		for(int j=2*i;j<=N;j+=i){
			pp[j]=1;
			factor[j].push_back(i);
		}
	}
	if(N > 3){
		puts("2");
	}
	else{
		puts("1");
	}
	for(int i=2;i<=N;i++){
		printf("%d ", pp[i]+1);
	}
	return 0;
}