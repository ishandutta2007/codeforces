/* 




D P 




 l l
*/
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
int x,m;
inline int gcd(int a,int b){
	return (b==0)?a:gcd(b,a%b);
}
inline int getsum(int n,vector<int> fac){
	int sz=fac.size(),ans=0;
	for(int i=0;i<(1<<sz);i++){
		int num=1;
		for(int j=0;j<sz;j++){
			if(i>>j&1)	num=num*fac[j];
		}
		if(__builtin_popcount(i)%2==1)	ans-=n/num;
		else							ans+=n/num;
	}
	return ans;
}
inline void solve(){
	x=read(),m=read();
	int g=gcd(x,m);
	x/=g;m/=g;
	vector<int> fac;
	int tmp=m;
	for(int i=2;i*i<=m;i++){
		if(tmp%i==0){
			fac.push_back(i);
			while(tmp%i==0)	tmp/=i;
		}
	}
	if(tmp>1)	fac.push_back(tmp);
	cout<<getsum(x+m-1,fac)-getsum(x-1,fac)<<endl;
}
signed main(){
	int T=read();while(T--)	solve();
	return 0;
}