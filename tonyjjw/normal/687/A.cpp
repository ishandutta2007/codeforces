#include<stdio.h>
#include<vector>
#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int MN = 100000 + 5;

int N,M;
int par[MN];
int rel[MN];
int color[MN];

int find(int n){
	if(par[n]==n)return n;
	int p = find(par[n]);
	rel[n]^=rel[par[n]];
	return par[n]=p;
}

bool merge(int a,int b){
	int p1 = find(a);
	int p2 = find(b);
	if(p1!=p2){
		par[p2]=p1;
		rel[p2]=rel[a]^rel[b]^1;
		return false;
	}
	else{
		if(rel[a]^rel[b]==0) return true;
		return false;
	}
}
vector<int> A,B;

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) par[i] = i;
	for(int i=0;i<M;i++){
		II(a)II(b); a--,b--;
		if(merge(a,b)){
			printf("-1\n");
			return 0;
		}
	}
	int cnt=0;
	for(int i=0;i<N;i++)if(par[i]==i){
		color[i] = cnt;
		cnt^=1;
	}
	for(int i=0;i<N;i++)if(par[i]!=i){
		int p = find(i);
		color[i] = color[p] ^ rel[i];
	}
	for(int i=0;i<N;i++){
		if(color[i]){
			A.push_back(i);
		}
		else{
			B.push_back(i);
		}
	}
	printf("%d\n",A.size());
	for(auto &n:A) printf("%d ",n+1);
	printf("\n%d\n",B.size());
	for(auto &n:B) printf("%d ",n+1);
	return 0;
}