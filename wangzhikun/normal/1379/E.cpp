//copied
#include<bits/stdc++.h>
using namespace std;
int N,K,cnt;
int can(int n,int k){
	if(n%2==0)return 0;
	if(k==0){
		if(n&(n+1))return 0;
		else return 1;
	}
	if(k==1){
		if(n&(n+1))return 1;
		else return 0;
	}
	if(n==9&&k==2)return 0;
	return k>0&&k*2+3<=n;
}
void dfs(int n,int k,int pre){
	printf("%d ",pre);
	int x=++cnt;
	if(n==1)return;
	for(int l=1;l<n;l=l*2+1){
		int r=n-l-1;
		int kr=k-(max(l,r)>=(min(l,r)<<1));
		if(can(l,0)&&can(r,kr)){
			dfs(l,0,x);
			dfs(r,kr,x);
			return;
		}
	}
}
int main()
{
	scanf("%d%d",&N,&K);
	if(!can(N,K)){puts("NO");return 0;}
	puts("YES");
	dfs(N,K,0);
}