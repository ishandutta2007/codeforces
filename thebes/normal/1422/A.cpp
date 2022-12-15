#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second

const int MN = 1005;
long long T, A, B, C, i;

int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld",&A,&B,&C);
		printf("%lld\n",(long long)(A+B+C-1));
	}
	return 0;
}