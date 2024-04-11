#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define maxn 100005
using namespace std;
int tic[maxn];
int dp[maxn];
int n;
int Binary_Search(int l,int r,int x){
	if(l==r)return l;
	int m=(r-l)/2+l;
	if(tic[m]>=x)return Binary_Search(l,m,x);
	return Binary_Search(m+1,r,x);
}
int DP(int pos){
	if(pos<=0)return 0;
	if(dp[pos])return dp[pos];
	int& ans=dp[pos];
	ans=min(DP(pos-1)+20,min(DP(Binary_Search(0,n,tic[pos]-89)-1)+50,DP(Binary_Search(0,n,tic[pos]-1439)-1)+120));
	return ans;
}
int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&tic[i]);
	printf("%d\n",DP(1));
	for(int i=2;i<=n;i++)printf("%d\n",DP(i)-dp[i-1]);
	return 0;
}