#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#include<stdlib.h>
#include<set>
using namespace std;

#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
#define DBG if(1)
#define NDBG if(0)

typedef long long ll;
typedef pair<int,int> pii;

const int MN = 50000 + 5;

int N;
set<int> S;

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		II(a); S.insert(a);
	}
	while(true){
		auto it = S.rbegin();
		int old = *it;
		int n = *it;
		while(S.find(n) != S.end()){
			n /= 2;
		}
		if(n == 0)break;
		S.erase(old);
		S.insert(n);
	}
	for(auto &n: S)printf("%d ",n);
	return 0;
}