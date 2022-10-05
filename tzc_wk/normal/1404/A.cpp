/*
Contest: Codeforces Round #668 (Div.1)
Problem: Codeforces 1404A
Author: tzc_wk
Time: 2020.9.6
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
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n,k;char s[300005];
int sum1[300005],sum0[300005];
char p[300005];
inline void solve(){
	cin>>n>>k>>s+1;fz(i,0,n) p[i]='?';
	fz(i,1,n){
		if(s[i]=='?') continue;
		if(p[(i-1)%k]!='?'&&p[(i-1)%k]!=s[i]){
//			cout<<i<<endl;
			puts("NO");return;
		}
		if(p[(i-1)%k]=='?') p[(i-1)%k]=s[i];
	}
	int cnt1=0,cnt0=0;
	fz(i,0,k-1){
		if(p[i]=='1') cnt1++;
		if(p[i]=='0') cnt0++;
	}
//	puts("-1");
	if(cnt1>k/2||cnt0>k/2) puts("NO");
	else puts("YES");
}
int main(){
	int T=read();
	while(T--) solve();
	return 0;
}