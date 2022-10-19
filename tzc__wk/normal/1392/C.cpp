/*
Contest: Codeforces Global Round 10
Problem: Codeforces 1392C
Author: tzc_wk
Time: 2020.8.16
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
int a[200005];
int main(){
	int T=read();while(T--){
		int n=read();fz(i,1,n) a[i]=read();
		ll sum=0;fz(i,1,n-1) if(a[i]-a[i+1]>0) sum+=a[i]-a[i+1];
		printf("%lld\n",sum);
	}
	return 0;
}