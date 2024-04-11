#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define int long long
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
int a[100005],n,s,sum[100005];
inline void solve(){
	memset(sum,0,sizeof(sum));
	n=read();s=read();
	fz(i,1,n)	a[i]=read(),sum[i]=sum[i-1]+a[i];
	if(sum[n]<=s){
		puts("0");
		return;
	}
	int mxans=0,t=0;
	fz(i,1,n){
		int l=1,r=n,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			int k=sum[mid],num=mid;
			if(mid>=i)	k-=a[i],num--;
			if(k<=s)	ans=num,l=mid+1;
			else		r=mid-1;
		}
		if(ans>mxans)	t=i,mxans=ans;
	}
	print(t);eoln;
}
signed main(){
	int T=read();
	while(T--)	solve();
	return 0;
}