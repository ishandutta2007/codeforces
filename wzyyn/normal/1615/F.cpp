#include<bits/stdc++.h>

using namespace std;

const int mo=1000000007;
const int N=2005;
char s[N],t[N];
int n,f[N*2],g[N*2];
int nf[N*2],ng[N*2];
void solve(){
	scanf("%d%s%s",&n,s+1,t+1);
	for (int i=1;i<=n;i+=2){
		if (s[i]!='?') s[i]^=1;
		if (t[i]!='?') t[i]^=1;
	}
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	f[N]=1;
	for (int i=1;i<=n;i++){
		int d=min(i,n-i+1);
		if (s[i]!='1'){
			memcpy(nf,f,sizeof(f));
			memcpy(ng,g,sizeof(g));
		}
		else{
			memset(nf,0,sizeof(nf));
			memset(ng,0,sizeof(ng));
		}
		if (s[i]!='0'){
			for (int j=N-d;j<=N+d;j++){
				nf[j+1]=(nf[j+1]+f[j])%mo;
				ng[j+1]=(ng[j+1]+g[j])%mo;
			}
		}
		if (t[i]!='1'){
			memcpy(f,nf,sizeof(f));
			memcpy(g,ng,sizeof(g));
		}
		else{
			memset(f,0,sizeof(nf));
			memset(g,0,sizeof(ng));
		}
		if (t[i]!='0'){
			for (int j=N-d;j<=N+d;j++){
				f[j-1]=(f[j-1]+nf[j])%mo;
				g[j-1]=(g[j-1]+ng[j])%mo;
			}
		}
		for (int j=N-d;j<=N+d;j++)
			g[j]=(g[j]+1ll*abs(j-N)*f[j])%mo;
	}
	cout<<g[N]<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}