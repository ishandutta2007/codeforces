#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=200005;
int n,k;
char s[N];
int p[N][20];
int nx[N][20];
int f[N];

bool check(int mid){
	memset(f,3,sizeof(f));
	f[0]=1;
	for (int j=1;j<=k;j++)
		nx[n+1][j]=n+2;
	for (int i=n;i>=1;i--){
		for (int j=1;j<=k;j++)
			nx[i][j]=nx[i+1][j];
		if (i+mid-1<=n)
			for (int j=1;j<=k;j++)
				if (p[i+mid-1][j]-p[i-1][j]==mid)
					nx[i][j]=i+mid;
	}
	for (int i=0;i<1<<k;i++)
		if (f[i]<=n+1)
			for (int j=0;j<k;j++)
				if (!(i&(1<<j))&&nx[f[i]][j+1]<=n+1)
					f[i|(1<<j)]=min(f[i|(1<<j)],nx[f[i]][j+1]);
	return f[(1<<k)-1]<=n+1;
}
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=k;j++)
			p[i][j]=p[i-1][j]+(s[i]=='?'||s[i]=='a'+j-1);
	int l=1,r=n/k,ans=0;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;
}