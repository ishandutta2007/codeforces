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
int n=read(),mod=read();
int f[250005];
signed main(){
	f[0]=1;
	fz(i,1,250000){
		f[i]=f[i-1]*i%mod;
	}
	int ans=0;
	fz(i,1,n){
		ans=(ans+(n-i+1)*(n-i+1)%mod*f[i]%mod*f[n-i]%mod)%mod;
	}
	print(ans);
	return 0;
}