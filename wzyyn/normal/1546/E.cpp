#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=505;
int n;
int a[2*N][N];
int S[N][N],ban[N*2],chk[N*2];
int q[N*2],e[N*2][N*2];
int vi[N][N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			S[i][j]=0;
	for (int i=1;i<=2*n;i++){
		for (int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			++S[j][a[i][j]];
		}
		ban[i]=chk[i]=0;
	}
	bool flag=1;
	for (;;){
		bool flag=0;
		for (int i=1;i<=2*n;i++)
			if (!ban[i]&&!chk[i]){
				bool sam=0;
				for (int j=1;j<=n;j++)
					if (S[j][a[i][j]]==1) sam=1;
				if (!sam) continue;
				chk[i]=1; flag=1;
				for (int k=1;k<=n;k++) --S[k][a[i][k]];
				for (int k=1;k<=2*n;k++)
					if (!ban[k]&&!chk[k]){
						bool sam=0;
						for (int l=1;l<=n;l++)
							if (a[i][l]==a[k][l]) sam=1;
						if (sam){
							ban[k]=1;
							for (int l=1;l<=n;l++)
								--S[l][a[k][l]];
						}
					}
			}
		if (!flag) break;
	}
	for (int i=1;i<=n*2;i++)
		for (int j=1;j<=n*2;j++)
			e[i][j]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			vi[i][j]=0;
	for (int i=1;i<=n*2;i++)
		if (!ban[i]&&!chk[i]){
			for (int j=1;j<=n;j++)
				if (!vi[j][a[i][j]])
					vi[j][a[i][j]]=i;
				else{
					int x=vi[j][a[i][j]];
					e[i][x]=e[x][i]=1;
					//cout<<"E "<<x<<' '<<i<<endl;
				}
		}
	int ans=1;
	for (int i=1;i<=n*2;i++)
		if (!ban[i]&&!chk[i]){
			int h=0,t=1;
			q[1]=i; chk[i]=1;
			ans=2*ans%998244353;
			while (h!=t){
				int x=q[++h];
				for (int j=1;j<=n*2;j++)
					if (!chk[j]&&!ban[j]&&e[x][j]){
						chk[j]=ban[x]; ban[j]=chk[x];
						q[++t]=j;
					}
			}
		}
	printf("%d\n",ans);
	for (int i=1;i<=2*n;i++)
		if (chk[i]) printf("%d ",i);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}