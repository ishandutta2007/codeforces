#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=1000;
const int M=2520;
vector<int> E[N];
int k[N],was[N*M],dp[N*M];
int go(int x){
	int a,b;tie(a,b)=mp(x/M,x%M);
	//printf("%i %i %i\n",a,b,b%E[a].size(),E[a][1]);
	int A=E[a][b%((int)E[a].size())];
	int B=((b+k[A])%M+M)%M;
	int y=A*M+B;
	return y;
}
void DFS(int x,int t){
	if(was[x])return;
	was[x]=t;
	//printf("%i %i\n",x/M+1,x%M);
	int y=go(x);
	if(!was[y])DFS(y,t),dp[x]=dp[y];
	else if(was[y]!=t)dp[x]=dp[y];//,printf("stop :D\n");
	else{
		//printf("dest %i %i\n",y/M+1,y%M);
		set<int> nodes;
		y=x;
		do{
			nodes.insert(y/M);
			y=go(y);
		}while(y!=x);
		dp[x]=nodes.size();
	}
}
int main(){
	int n;
	scanf("%i",&n);
	for(int i=0;i<n;i++)scanf("%i",&k[i]);
	for(int i=0;i<n;i++){
		int sz;
		scanf("%i",&sz);
		E[i].resize(sz);
		for(int &j:E[i])scanf("%i",&j),j--;
	}
	int q;
	scanf("%i",&q);
	for(int i=1;i<=q;i++){
		int u,c;
		scanf("%i %i",&u,&c);
		u--;c=((c+k[u])%M+M)%M;
		DFS(u*M+c,i);
		printf("%i\n",dp[u*M+c]);
	}
	//printf("%i %i\n",go(0*M+1)/M+1,go(0*M+1)%M);
	return 0;
}