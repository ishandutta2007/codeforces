#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=105;
int n,c0,c1;
int f[N][N][2][2];
bool sg(int i,int j,int a,int b){
	if(i==1){
		if(a)return j==b;
		else return b;	
	}
	if(f[i][j][a][b]>=0)return f[i][j][a][b];
	int res=0;
	if(i-j>0)res|=!sg(i-1,j,a^1,b);
	if(j>0)res|=!sg(i-1,j-1,a^1,b^a);
	return f[i][j][a][b]=res;
}
void solve(){
	n=in();c0=c1=0;
	for(int i=1;i<=n;i++){
		int x=in();
		if(x&1)c1++;
		else c0++;	
	}
	if(sg(n,c1,1,0))puts("Alice");
	else puts("Bob");
}
int main(){
	memset(f,-1,sizeof(f));
	int t=in();
	while(t--)solve();
	return 0;
}