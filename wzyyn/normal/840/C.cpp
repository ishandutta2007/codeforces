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
const int mo=1000000007;
const int N=305;
int n,m,ans;
int a[N],C[N][N];
int f[N],g[N];
map<int,int> mp;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s; 
}
void init(){
	For(i,0,N-1) C[i][0]=1;
	For(i,1,N-1) For(j,1,i)
		C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
}

int ord(int x){
	for (int i=2;1ll*i*i<=x;i++)
		for (;x%(i*i)==0;x/=i*i);
	return x;
}
void insert(int n){
	if (m){
		memset(g,0,sizeof(g));
		For(i,1,n){
			int tr=C[n-1][i-1];
			For(j,0,m-1) For(k,0,min(i,j)){
				int nj=j+(n-i)-k;
				int vtr=1ll*tr*C[m+1-j][i-k]%mo*C[j][k]%mo;
				g[nj]=(g[nj]+1ll*vtr*f[j])%mo;
			}
		}
		memcpy(f,g,sizeof(f));
	}
	else
		f[n-1]=ans;
	m+=n;
}
int main(){
	ans=1;
	init();
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) a[i]=ord(a[i]);
	For(i,1,n) ans=1ll*ans*(++mp[a[i]])%mo;
	//cerr<<ans<<endl;
	For(i,1,n) if (mp[a[i]])
		insert(mp[a[i]]),mp[a[i]]=0;
	printf("%d\n",f[0]);
}