#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define y1 fdhjksa
using namespace std;
const int mo=1000000007;
const int N=2005;
int n,m;
char mp[N][N];
int S1[N][N],S2[N][N];
int f1[N][N],f2[N][N];
void update(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%s",mp[i]+1);
	For(i,1,n) For(j,1,m) S1[i][j]=S2[i][j]=(mp[i][j]=='R');
	Rep(i,n,1) Rep(j,m,1) S1[i][j]+=S1[i][j+1];
	Rep(i,n,1) Rep(j,m,1) S2[i][j]+=S2[i+1][j];
	f1[1][1]=1; f1[1][m-S1[1][2]+1]=mo-1;
	For(i,1,n) For(j,1,m){
		int v1=f1[i][j]=(f1[i][j]+f1[i][j-1])%mo;
		int v2=f2[i][j]=(f2[i][j]+f2[i-1][j])%mo;
		//printf("%d %d %d %d\n",i,j,v1,v2);
		update(f2[i+1][j],v1);
		update(f2[n-S2[i+1][j]+1][j],mo-v1);
		update(f1[i][j+1],v2);
		update(f1[i][m-S1[i][j+1]+1],mo-v2);
	}
	printf("%d\n",(f1[n][m]+f2[n][m])%mo);
}