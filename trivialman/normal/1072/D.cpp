#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
#define N 2010
#define LL long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define CL(a) memset(a,0,sizeof(a))

char a[N][N];
int dp[N][N];
bool ok[N][N];
int n,k;

int main(){
	cin>>n>>k;
	rep(i,1,n){
		cin>>a[i];
		for(int j=n;j;j--)a[i][j]=a[i][j-1];
		a[i][0]=0;
	}
	CL(dp);
	int numa=2*n-1,sumij=0;
	rep(u,2,2*n){
		int maxa=0;
		rep(i,max(1,u-n),min(u-1,n)){
			int j=u-i;
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+(a[i][j]=='a');
			if(dp[i][j]>maxa)maxa=dp[i][j];
		}
		if(u-1-maxa>k){
			numa=u-2;
			break;
		}
	}
	rep(i,1,numa)cout<<'a';
	string ans="";
	CL(ok);
	
	int u=numa+1;
	bool flag=false;
	rep(i,max(1,u-n),min(u-1,n)){
		int j=u-i;
		if(dp[i][j]==numa-k){
			ok[i][j]=true;
			flag=true;
		}
	}
	if(!flag)rep(i,max(0,u-n),min(u-1,n))ok[i][u-i]=true;
	
	//cout<<numa+2<<endl;
	rep(u,numa+2,2*n){
		char minch='z';
		rep(i,max(1,u-n),min(u-1,n)){
			int j=u-i;
			//cout<<ok[i-1][j]<<" "<<ok[i][j-1]<<endl; 
			if(ok[i-1][j]||ok[i][j-1]){
				minch=min(minch,a[i][j]);
			}
		}
		ans+=minch;
		//cout<<u<<" "<<ans<<endl;
		rep(i,max(1,u-n),min(u-1,n)){
			int j=u-i;
			if(ok[i-1][j]||ok[i][j-1]){
				if(a[i][j]==minch)ok[i][j]=true;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}