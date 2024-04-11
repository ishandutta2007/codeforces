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

const int MN = 100000 + 10;

int N;
int C[MN];
vector<int> E[MN];
int a[MN], b[MN];

bool dfs(int n, int bef){
	for(auto &t: E[n])if(t!=bef){
		if(C[n]!=C[t] || dfs(t, n)) return true;
	}
	return false;
}

bool check(int n){
	for(auto &t: E[n]){
		if(dfs(t, n)) return false;
	}
	return true;
}

int main(){
	scanf("%d", &N);
	for(int i=0;i<N-1;i++){
		scanf("%d%d",&a[i], &b[i]); a[i]--, b[i]--;
		E[a[i]].push_back(b[i]), E[b[i]].push_back(a[i]);
	}
	for(int i=0;i<N;i++) scanf("%d", &C[i]);
	for(int i=0;i<N-1;i++){
		if(C[a[i]] != C[b[i]]){
			if(check(a[i])){
				puts("YES");
				printf("%d\n", a[i]+1);
			}
			else if(check(b[i])){
				puts("YES");
				printf("%d\n", b[i]+1);
			}
			else{
				puts("NO");
			}
			return 0;
		}
	}
	puts("YES");
	puts("1");
	return 0;
}