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
int T=read(),n,a[200005]; 
inline void solve(){
	n=read();
	fz(i,1,n)	a[i]=read();
	fz(i,1,n-1)	if(abs(a[i+1]-a[i])>=2){
		puts("YES");
		cout<<i<<" "<<i+1<<endl;
		return;
	}
	puts("NO");
}
int main(){
	while(T--)	solve();
	return 0;
}