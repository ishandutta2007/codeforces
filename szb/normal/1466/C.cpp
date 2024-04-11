#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define For(i,x,y)	for(ll i=(x);i<=(y);++i)
#define FOr(i,x,y)	for(ll i=(x);i>=(y);--i)
#define rep(i,x,y)	for(ll i=(x);i<(y);++i)
#define clr(a,v)	memset(a,v,sizeof(a))
#define cpy(a,b)	memcpy(a,b,sizeof(a))
#define fi	first
#define se	second
#define	pb	push_back
#define mk	make_pair
#define pa	pair<ll,ll>
#define y1	y11111111111111
#define debug	puts("@@@@@@@@@@@@@@@@@@@@@@@")
ll read(){
	ll x=0,f=1;	char ch=getchar();	
	for(;ch<'0'||ch>'9';ch=getchar())	if (ch=='-')	f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())	x=x*10+ch-'0';
	return x*f;
}
void write(ll x){
	if (x<0)	putchar('-'),write(-x);
	else{
		if (x>=10)	write(x/10);
		putchar(x%10+'0');
	}
}
const ll N=402000;
ll n,a[N],b[N],c[N],f[N][2][2],ans;
char s[N];
int main(){
	ll T=read();
	for(;T--;){
		scanf("%s",s+1);
		n=strlen(s+1);
		if (n==1){
			puts("0");
			continue;
		}
		For(i,1,n)a[i]=s[i]-'a';
		f[2][0][0]=0;
		f[2][0][1]=f[2][1][0]=1;
		f[2][1][1]=2;
		if (a[1]==a[2]){
			f[2][0][0]=1e9;
		}
		For(i,3,n)f[i][0][0]=f[i][0][1]=f[i][1][0]=f[i][1][1]=1e9;
		For(i,3,n)For(u,0,1)For(v,0,1)For(w,0,1){
			if ((!u)&&(!v)&&(a[i-2]==a[i-1]))continue;
			if ((!u)&&(!w)&&(a[i-2]==a[i]))continue;
			if ((!v)&&(!w)&&(a[i-1]==a[i]))continue;
			f[i][v][w]=min(f[i][v][w],f[i-1][u][v]+w);
		}
		cout<<min(min(min(f[n][0][0],f[n][0][1]),f[n][1][0]),f[n][1][1])<<endl;
	}
}