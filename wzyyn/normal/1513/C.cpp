#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;
const int N=200005;
const int mo=1000000007;

int f[N][10];
int main(){
	for (int i=0;i<=9;i++) f[0][i]=1;
	for (int i=1;i<N;i++){
		for (int j=0;j<=8;j++)
			f[i][j]=f[i-1][j+1];
		f[i][9]=(f[i-1][1]+f[i-1][0])%mo;
	}
	
	int T;
	scanf("%d",&T);
	while (T--){
		int n,m;
		scanf("%d%d",&n,&m);
		int ans=0;
		for (;n;n/=10)
			ans=(ans+f[m][n%10])%mo;
		printf("%d\n",ans);
	}
}