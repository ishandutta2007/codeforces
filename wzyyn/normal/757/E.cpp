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
const int N=1000005;
int f[N][22];
int mn[N];
int main(){
	f[0][0]=1;
	For(i,1,19) f[0][i]=2;
	For(i,1,N-1){
		f[i][0]=f[i-1][0];
		For(j,1,19) f[i][j]=(f[i][j-1]+f[i-1][j])%mo;
	} 
	For(i,2,N-1) if (!mn[i])
		For(j,1,(N-1)/i) if (!mn[i*j]) mn[i*j]=i;
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int x,r;
		scanf("%d%d",&r,&x);
		int ans=1;
		for (;x!=1;){
			int v=mn[x],t=0;
			for (;x%v==0;x/=v,t++);
			ans=1ll*ans*f[r][t]%mo;
		}
		printf("%d\n",ans);
		//cout<<ans<<endl;
	}
}