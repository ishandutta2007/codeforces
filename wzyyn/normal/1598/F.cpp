#include<bits/stdc++.h>

using namespace std;

const int N=400005;
int n;
char s[N];
int tg[21][N];
int mnv[21],sum[21];
int f[(1<<20)|5],ans;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%s",s+1);
		int l=strlen(s+1);
		int mn=0,ss=0;
		for (int j=1;j<=l;j++){
			if (s[j]=='(') ++ss;
			else --ss;
			if (ss<mn) mn=ss;
			if (ss==mn) ++tg[i][-ss];
		}
		mnv[i]=mn;
		sum[i]=ss;
	}
	memset(f,233,sizeof(f));
	f[0]=0;
	for (int i=0;i<1<<n;i++){
		if (f[i]<0) continue;
		int s=0;
		for (int j=0;j<n;j++)
			if (i&(1<<j)) s+=sum[j];
		if (s<0) continue;
		//cout<<i<<' '<<f[i]<<endl;
		for (int j=0;j<n;j++)
			if (!(i&(1<<j))){
				int nv=tg[j][s]+f[i];
				ans=max(ans,nv);
				if (s+mnv[j]>=0) f[i|(1<<j)]=max(f[i|(1<<j)],nv);
			}
	}
	cout<<ans<<endl;
}