#include<bits/stdc++.h>

using namespace std;

const int N=1005;
int f[N];
void init(){
	memset(f,30,sizeof(f));
	f[1]=0;
	for (int i=1;i<N;i++)
		for (int j=1;j<=i;j++)
			if (i+i/j<N) f[i+i/j]=min(f[i+i/j],f[i]+1);
}
int g[N*13],b[N],c[N],n,k;
void solve(){
	scanf("%d%d",&n,&k);
	k=min(k,n*13);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]),b[i]=f[b[i]];
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	memset(g,233,sizeof(int)*(13*n+5));
	g[0]=0; int S=0;
	for (int i=1;i<=n;i++){
		for (int j=S;j>=0;j--)
			g[j+b[i]]=max(g[j+b[i]],g[j]+c[i]);
		S+=b[i];
	}
	cout<<*max_element(g,g+k+1)<<endl;
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}