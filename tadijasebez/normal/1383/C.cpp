#include <bits/stdc++.h>
using namespace std;
const int N=100050;
const int M=20;

char A[N],B[N];
vector<int> E[M];
int out[M];
bool dp[1<<M];
bool was[M];
void DFS(int u){
	was[u]=true;
	for(int v:E[u]){
		if(!was[v]){
			DFS(v);
		}
	}
}
int main(){
	int t;
	scanf("%i",&t);
	while(t--){
		int n;
		scanf("%i",&n);
		scanf("%s",A+1);
		scanf("%s",B+1);
		for(int i=1;i<=n;i++){
			E[A[i]-'a'].push_back(B[i]-'a');
			E[B[i]-'a'].push_back(A[i]-'a');
			out[A[i]-'a']|=1<<(B[i]-'a');
		}
		int comp=0;
		for(int i=0;i<M;i++){
			if(!was[i]){
				comp++;
				DFS(i);
			}
		}
		dp[0]=true;
		int best=0;
		for(int mask=0;mask<(1<<M);mask++){
			if(dp[mask]){
				best=max(best,__builtin_popcount(mask));
				for(int i=0;i<M;i++){
					if(!(mask>>i&1)){
						if((out[i]&mask)==0){
							dp[mask|(1<<i)]=true;
						}
					}
				}
			}
		}
		printf("%i\n",M*2-comp-best);
		for(int i=0;i<M;i++){
			E[i].clear();
			was[i]=false;
			out[i]=0;
		}
		for(int mask=0;mask<(1<<M);mask++){
			dp[mask]=false;
		}
	}
	return 0;
}