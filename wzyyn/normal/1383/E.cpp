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
char s[N];
int pre[N],suf[N];
int n,f[N],sf[N],ans;
int q[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	For(i,1,n) pre[i]=(s[i]=='0'?pre[i-1]+1:0);
	Rep(i,n,1) suf[i]=(s[i]=='0'?suf[i+1]+1:0);
	if (pre[n]==n){
		printf("%d\n",n);
		return 0;
	}
	int s1=1,t=1;
	q[1]=0; pre[0]=1<<30;
	For(i,1,n){
		if (s[i]=='1'){
			for (;t&&pre[q[t]]<pre[i-1];--t);
			q[++t]=i-1;
			f[i]=s1;
			if (s[i-1]=='0')
				for (int j=i-1;s[j]=='0';--j)
					f[i]=(f[i]+f[j])%mo;
			s1=f[i];
		}
		else{
			if (i==pre[i]) ++f[i];
			for (;pre[q[t]]<pre[i];--t);
			f[i]=(f[i]+sf[i-1]+1ll*mo-sf[q[t]])%mo;
		}
		sf[i]=sf[i-1];
		if (s[i]=='1') sf[i]=(sf[i]+f[i])%mo;
		//cout<<f[i]<<endl;
	}
	int ans=0;
	int l=1;
	for (;s[l]=='0';++l);
	Rep(i,n,l)
		if (pre[i]<=pre[n])
			ans=(ans+f[i])%mo;
	cout<<ans<<endl; 
}
/*

*/