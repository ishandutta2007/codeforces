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
const int MOD=998244353;
int n=read();
vector<int> g[1000005];
int cnt[1000005];
inline int exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;y=0;
		return a;
	}
	int t=exgcd(b,a%b,x,y);
	int temp=x;
	x=y;
	y=temp-(a/b)*y;
	return t;
}
inline int inv(int a,int b){
	int x,y;exgcd(a,b,x,y);
	return (x+b)%b;
}
signed main(){
	fz(i,1,n){
		int x=read();
		fz(j,1,x){
			int y=read();
			g[i].push_back(y);
			cnt[y]++;
		}
	}
	int sum=0;
	fz(i,1,n){
		for(int j=0;j<g[i].size();j++){
			int x=g[i][j];
//			cout<<cnt[x]-1<<"/"<<n*g[i].size()*n<<endl;
			sum=(sum+1ll*inv(n,MOD)*inv(g[i].size(),MOD)%MOD*inv(n,MOD)%MOD*(cnt[x])%MOD)%MOD;
		}
	}
	print(sum);eoln;
	return 0;
}