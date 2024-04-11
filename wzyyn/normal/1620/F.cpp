#include<bits/stdc++.h>

using namespace std;

const int N=1000005;
int n,a[N];
int f[N][2][2];
pair<int,int> pr[N][2][2];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=0;i<=n+1;i++)
		memset(f[i],66,sizeof(f[i]));
	f[1][0][0]=f[1][0][1]=-(1<<30);
	for (int i=1;i<n;i++)
		for (int j=0;j<2;j++)
			for (int s=0;s<2;s++)
				if (f[i][j][s]<=(1<<30))
					for (int ns=0;ns<2;ns++){
						int x=(s?-a[i]:a[i]);
						int y=f[i][j][s];
						if (j) swap(x,y);
						int z=(ns?-a[i+1]:a[i+1]);
						//x>y
						if (z>x){
							if (y<f[i+1][0][ns]){
								f[i+1][0][ns]=y;
								pr[i+1][0][ns]=pair<int,int>(j,s);
							}
						} 
						else if (z>y){
							if (x<f[i+1][1][ns]){
								f[i+1][1][ns]=x;
								pr[i+1][1][ns]=pair<int,int>(j,s);
							}
						}
					}
	int pj=-1,ps=-1;
	for (int j=0;j<2;j++)
		for (int s=0;s<2;s++)
			if (f[n][j][s]<=(1<<30))
				pj=j,ps=s;
	if (pj==-1) puts("NO");
	else{
		puts("YES");
		for (int i=n;i>=1;i--){
			if (ps) a[i]*=-1;
			if (i==1) break;
			pair<int,int> tmp=pr[i][pj][ps];
			pj=tmp.first; ps=tmp.second;
		}
		for (int i=1;i<=n;i++)
			printf("%d ",a[i]);
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}