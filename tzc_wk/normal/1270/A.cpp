#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
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
int T=read(),n,k1,k2,a[105],b[105];
inline void solve(){
	int n=read(),k1=read(),k2=read();
	fz(i,1,k1)	a[i]=read();
	fz(i,1,k2)	b[i]=read();
	sort(a+1,a+k1+1);
	sort(b+1,b+k2+1);
	if(a[k1]>=b[k2])	puts("YES");
	else				puts("NO");
}
int main(){
	while(T--)	solve();
	return 0;
}