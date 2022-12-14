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

const int MN = 50000 + 5;
const int MT = 1000000 + 5;

int N, M;
int col[MN];
int sz[MN];
int tcol[MT];
vector<int> E[MN];
vector<int> tlist[MN];

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		II(a)II(b);
		if(a > b) swap(a, b);
		a--, b--;
		E[b].push_back(a);
	}
	int T = 0;
	for(int i=0;i<N;i++){
		scanf("%d",&sz[i]);
		for(int j=0;j<sz[i];j++){
			II(a);
			tlist[i].push_back(a);
			T = max(T, a);
		}
	}
	for(int i=0;i<N;i++){
		int v=0;
		for(int j: E[i]){
			if(col[j]==0) v--;
			else v++;
		}
		if(v<0) col[i] = 1;
	}
	while(true){
		for(int i=1;i<=T;i++){
			tcol[i] = (rand()>>3)&1;
		}
		bool flag = true;
		for(int i=0;i<N;i++){
			int v=0;
			for(auto &t: tlist[i]){
				if(tcol[t] == col[i]) v++;
			}
			if(v==0){
				flag = false;
				break;
			}
		}
		if(flag) break;
	}
	for(int i=0;i<N;i++){
		for(auto &t: tlist[i]){
			if(tcol[t] == col[i]){
				printf("%d ", t);
				break;
			}
		}
	}
	puts("");
	for(int i=1;i<=T;i++) printf("%d ", tcol[i]+1);
	puts("");
	return 0;
}