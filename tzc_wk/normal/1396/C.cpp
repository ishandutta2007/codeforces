/*
Contest: Codeforces Round #666 (Div.1)
Problem: Codeforces 1396C
Author: tzc_wk
Time: 2020.8.30
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
#define int long long
typedef pair<int,int> pii;
typedef long long ll;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n=read(),r1=read(),r2=read(),r3=read(),d=read(),a[1000005],dp[1000005],mn[1000005],mn2[1000005];
signed main(){
	fz(i,1,n) a[i]=read();
	fillbig(dp);fillbig(mn);fillbig(mn2);dp[0]=-d;
	fz(i,1,n){
		dp[i]=min(dp[i],dp[i-1]+r1*a[i]+r3+d);
		if(i!=1){
			if(i!=n) dp[i]=min(dp[i],mn[i-1]+d+min(r1*a[i]+r3,r2+d+d+r1));
			else dp[i]=min(dp[i],mn2[i-1]+d+min(r1*a[i]+r3,r2+d+d+r1));
			dp[i]=min(dp[i],dp[i-2]+d+min(r2,r1*(a[i-1]+1))+d+min(r2,r1*(a[i]+1))+d+r1+d+r1);
			dp[i]=min(dp[i],dp[i-1]+d+min(r2,r1*(a[i]+1))+d+d+r1);
		}
		mn[i]=min(mn[i-1]+min(r2,r1*(a[i]+1))+r1+d*3,dp[i]);
		mn2[i]=min(mn2[i-1]+min(r2,r1*(a[i]+1))+r1+d*2,dp[i]);
//		cout<<i<<" "<<dp[i]<<endl;
	}
	cout<<dp[n]<<endl;
	return 0;
}
/*
dp[i]=min(dp[j]+t[j+1]+t[j+2]+...+t[i]+r*(i-j)+3d*(i-j)-2d)

5 1 1 1000000000 1
1 2 3 4 5
*/