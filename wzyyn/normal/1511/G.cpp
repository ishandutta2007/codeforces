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

const int N=201000;
int n,m,Q;
int f[N][19];
int c[N][19];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		c[x][0]^=1;
	}
	for (int j=1;j<=17;j++)
		for (int i=1;i<=m-(1<<j)+1;i++){
			f[i][j]=f[i][j-1]^f[i+(1<<(j-1))][j-1];
			c[i][j]=c[i][j-1]^c[i+(1<<(j-1))][j-1];
			if (c[i+(1<<(j-1))][j-1])
				f[i][j]^=1<<(j-1);
		}
	scanf("%d",&Q);
	while (Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int bas=0,ans=0;
		for (int i=17;i>=0;i--)
			if (l+(1<<i)-1<=r){
				ans^=f[l][i];
				if (c[l][i]) ans^=bas;
				l+=(1<<i); bas+=(1<<i);
			}
		//cout<<ans<<' '<<bas<<endl;
		putchar(ans?'A':'B');
	}
}