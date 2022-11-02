 #include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int n;ll f[5009][5009],sum[5009][5009];
int lcp[5009][5009];//
char s[5009];
bool compar(int l1,int r1,int l2,int r2){
	if(r1-l1+1>r2-l2+1) return 1;
	if(r1-l1+1<r2-l2+1) return 0;
	int t=lcp[l1][l2];
	l1=l1+t,l2=l2+t;
	if(l1>r1||l2>r2) return 0;
	if(s[l1]>s[l2]) return 1;
	return 0;	
}
int main(){
	scanf("%d%s",&n,s+1);
	memset(lcp,0,sizeof(lcp));
	memset(f,0,sizeof(f));
	memset(sum,0,sizeof(sum));
	for(int i=n;i>=1;i--)
		for(int j=n;j>=1;j--)
			if(s[i]==s[j]) lcp[i][j]=lcp[i+1][j+1]+1;
	for(int i=1;i<=n;i++){
		if(s[1]!='0') f[i][1]=1,sum[i][i]=1;
		for(int j=2;j<=i;j++){
			if(s[j]=='0') continue;
			f[i][j]=(f[i][j]+sum[j-1][i-j])%mod;		
			int k=2*j-i-1;
			if(s[k]=='0'||k<=0) continue;
			if(compar(j,i,k,j-1)) f[i][j]=(f[i][j]+f[j-1][k])%mod;
		}
		for(int j=1;j<=n;j++)
			sum[i][j]=((sum[i][j]+(i-j+1>=1)?f[i][i-j+1]:0)%mod+sum[i][j-1])%mod;
	}
	ll ans=0;
	for(int i=1;i<=n;i++) ans=(ans+f[n][i])%mod;
	printf("%lld\n",ans);
	return 0;
}