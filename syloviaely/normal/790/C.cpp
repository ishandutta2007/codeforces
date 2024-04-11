#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int dp[80][80][80][2];
vector<int>A,B,C;
char ch[80];
int n,a,b,c;
void up(int &k1,int k2){
	k1=min(k1,k2);
}
int getA(int k1,int k2,int k3){
	int ans=0;
	for (int i=0;i<k2;i++) ans+=B[i]>A[k1];
	for (int i=0;i<k3;i++) ans+=C[i]>A[k1];
	return ans;
}
int getB(int k1,int k2,int k3){
	int ans=0;
	for (int i=0;i<k2;i++) ans+=A[i]>B[k1];
	for (int i=0;i<k3;i++) ans+=C[i]>B[k1];
	return ans;
}
int getC(int k1,int k2,int k3){
	int ans=0;
	for (int i=0;i<k2;i++) ans+=A[i]>C[k1];
	for (int i=0;i<k3;i++) ans+=B[i]>C[k1];
	return ans;
}
int main(){
	scanf("%d",&n); scanf("%s",ch+1);
	for (int i=1;i<=n;i++)
		if (ch[i]=='V'){
			A.push_back(i); a++;
		} else if (ch[i]=='K'){
			B.push_back(i); b++;
		} else {
			C.push_back(i); c++;
		}
	memset(dp,0x3f,sizeof dp); dp[0][0][0][0]=0;
	for (int i=0;i<n;i++){
		for (int x=0;x<=a;x++)
			for (int y=0;y<=b;y++){
				if (dp[i][x][y][0]<=1e9){
					int z=i-x-y; int w=dp[i][x][y][0];
					if (x<a) up(dp[i+1][x+1][y][1],w+getA(x,y,z));
					if (y<b) up(dp[i+1][x][y+1][0],w+getB(y,x,z));
					if (z<c) up(dp[i+1][x][y][0],w+getC(z,x,y));
				}
				if (dp[i][x][y][1]<=1e9){
					int z=i-x-y; int w=dp[i][x][y][1];
					if (x<a) up(dp[i+1][x+1][y][1],w+getA(x,y,z));
					if (z<c) up(dp[i+1][x][y][0],w+getC(z,x,y));
				}
			}
	}
	int ans=min(dp[n][a][b][0],dp[n][a][b][1]);
	cout<<ans<<endl; return 0;
}