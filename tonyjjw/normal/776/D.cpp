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

const int MN = 200000 + 100;

int N, M;
int A[MN];

vector<int> s[MN];
vector<int> E[2*MN];

int V[2*MN];
int color;
vector<int> order;

void dfs(int n){
	V[n]=color;
	for(int t: E[n])if(!V[t]){
		dfs(t);
	}
	order.push_back(n);
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d", &A[i]);
	}
	for(int i=0;i<M;i++){
		II(n);
		for(int j=0;j<n;j++){
			II(a); a--;
			s[a].push_back(i);
		}
	}
	for(int i=0;i<N;i++){
		int a = s[i][0], b = s[i][1];
		if(A[i]==0){
			E[2*a].push_back(2*b+1);
			E[2*a+1].push_back(2*b);
			E[2*b].push_back(2*a+1);
			E[2*b+1].push_back(2*a);
		}
		else{
			E[2*a].push_back(2*b);
			E[2*a+1].push_back(2*b+1);
			E[2*b].push_back(2*a);
			E[2*b+1].push_back(2*a+1);
		}
	}
	for(int i=0;i<2*M;i++){
		if(!V[i]){
			color++;
			dfs(i);
		}
	}
	reverse(all(order)); color=0;
	vector<int> aa = order;
	for(int i=0;i<2*M;i++) V[i]=0;
	for(int n: aa){
		if(!V[n]){
			color++;
			dfs(n);
		}
	}
	for(int i=0;i<M;i++){
		if(V[2*i] == V[2*i+1]){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}