/*
Contest: -
Problem: NFLSOJ 712
Author: tzc_wk
Time: 2020.10.20
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
int n;char s[1000005];
int posd[1000005],cntd=0;
int posb[1000005],cntb=0;
int dp[1000005];
int hav[1000005];
inline bool check(int mid){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=cntd;i++){
		if(dp[i-1]>=posd[i]||hav[posd[i]-1]==hav[dp[i-1]]) dp[i]=max(dp[i],posd[i]+mid);
		if(dp[i-1]>=posd[i]-mid||hav[posd[i]-mid-1]==hav[dp[i-1]]) dp[i]=max(dp[i],posd[i]);
		else return 0; 
		if(i>=2&&(dp[i-2]>=min(posd[i-1],posd[i]-mid-1)||hav[dp[i-2]]==hav[min(posd[i-1],posd[i]-mid)-1]))
			dp[i]=max(dp[i],max(posd[i],posd[i-1]+mid));
		dp[i]=min(dp[i],n);
//		printf("%d %d\n",i,dp[i]);
	}
	if(hav[dp[cntd]]==hav[n]) return 1;
	return 0;
}
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++) if(s[i]=='P') posd[++cntd]=i;
	for(int i=1;i<=n;i++) if(s[i]=='*') posb[++cntb]=i;
	posb[cntb+1]=n+1;
	for(int i=0;i<=cntb;i++){
		for(int j=posb[i];j<posb[i+1];j++) hav[j]=i;
	}
	if(cntd==1){
		int cntl=0,cntr=0,mxl=0,mxr=0;
		for(int i=1;i<=posd[1];i++) if(s[i]=='*') cntl++,mxl=max(mxl,posd[1]-i);
		for(int i=posd[1];i<=n;i++) if(s[i]=='*') cntr++,mxr=max(mxr,i-posd[1]);
		if(cntl>cntr) printf("%d %d\n",cntl,mxl);
		else if(cntr>cntl) printf("%d %d\n",cntr,mxr);
		else printf("%d %d\n",cntl,min(mxl,mxr));
		return 0;
	}
//	check(3);
	int l=1,r=n,ans=-23987;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d %d\n",cntb,ans);
	return 0;
}