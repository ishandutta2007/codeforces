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
long long n;
vector<long long> v;
signed main(){
	n=read();
	int ans=0;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			while(n%i==0)	n/=i;
			v.push_back(i);
		}
	}
	if(n>1)				v.push_back(n);
	if(v.size()==1)		print(v[0]);
	else					print(1);
	return 0;
}