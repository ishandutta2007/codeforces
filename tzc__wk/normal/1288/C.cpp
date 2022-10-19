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
int n=read(),m=read(),ans=0,C[2005][15];
const int MOD=1e9+7;
inline int calc(int x,int y){
	int cnt=m,sum=n-x+m-1;
//	cout<<sum<<" "<<m-1<<endl;
	int t1=1,t2=1;
	t1=C[sum][m-1];
	cnt=m,sum=y+m-2;
//	cout<<sum<<" "<<m-1<<endl;
	t2=C[sum][m-1];
//	cout<<x<<" "<<y<<" "<<t1<<" "<<t2<<endl;
	return t1%MOD*t2%MOD;
}
signed main(){
	C[0][0]=1;
	fz(i,1,2000){
		fz(j,0,10){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
		}
	}
	fz(i,1,n){
		fz(j,i,n){
			ans=(ans+calc(j,i))%MOD;
		}
	}
	print(ans);
	return 0;
}