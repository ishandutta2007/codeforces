#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int N;
char T[22][22];
char ch[44][22];
int l[44],r[44];

int dp[1<<20][44];
bool visited[1<<20][44];

int rec(int stat,int sum)
{
	if(visited[stat][sum]) return dp[stat][sum];
	visited[stat][sum]=true;
	if(sum==2*N-2)
	{
		if(ch[2*N-2][N-1]=='a') return dp[stat][sum]=1;
		else if(ch[2*N-2][N-1]=='b') return dp[stat][sum]=-1;
		else return dp[stat][sum]=0;
	}
	int tmp[26];
	for(int i=0;i<26;i++) tmp[i]=0;
	int pl=0;
	for(int i=0;i<N;i++){
		if((stat>>i)&1){
			if(ch[sum][i]=='a') pl=1;
			else if(ch[sum][i]=='b') pl=-1;
			for(int j=i;j<=i+1;j++){
				if(!(l[sum+1]<=j&&j<=r[sum+1])) continue;
				tmp[ch[sum+1][j]-'a']|=(1<<j);
			}
		}
	}
	int res;
	if(sum%2==0) res=200;
	else res=-200;
	for(int i=0;i<26;i++){
		if(tmp[i]==0) continue;
		int a=rec(tmp[i],sum+1);
		if(sum%2==0) res=min(res,a);
		else res=max(res,a);
	}
	res+=pl;
	return dp[stat][sum]=res;
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%s",T[i]);
		for(int j=0;j<N;j++) ch[i+j][j]=T[i][j];
	}
	for(int i=0;i<N;i++)
	{
		l[i]=0,r[i]=i;
	}
	for(int i=N;i<2*N-1;i++)
	{
		l[i]=i-N,r[i]=N-1;
	}
	int ans=rec(1,0);
	if(ans>0) printf("FIRST\n");
	else if(ans<0) printf("SECOND\n");
	else printf("DRAW\n");
	return 0;
}