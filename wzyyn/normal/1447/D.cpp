#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=5005;
int n,m;
char s[N],t[N];
int f[N][N];
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	scanf("%s",t+1);
	memset(f,233,sizeof(f));
	For(i,1,n) f[i][0]=0;
	For(i,1,m) f[0][i]=0;
	f[0][0]=0;
	int ans=0;
	For(i,1,n) For(j,1,m){
		f[i][j]=0;
		if (s[i]==t[j]) f[i][j]=max(f[i][j],f[i-1][j-1]+2);
		f[i][j]=max(f[i][j],f[i-1][j]-1);
		f[i][j]=max(f[i][j],f[i][j-1]-1);
		ans=max(ans,f[i][j]);
	}
	cout<<ans<<endl;
}