#include<bits/stdc++.h>
//#include<unistd.h>
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
const ll N=100010;
ll n,T,m,bin[100],f[10][10],ans;
int main(){
	f[3][0]=1;	f[3][1]=2;	f[3][2]=0;	f[3][3]=3;
	f[1][0]=2;	f[1][1]=3;	f[1][2]=0;	f[1][3]=1;
	f[2][0]=3;	f[2][1]=1;	f[2][2]=0;	f[2][3]=2;
	bin[0]=1;m=30;
	For(i,1,m)bin[i]=bin[i-1]*4;
	for(ll T=read();T--;){
		n=read();ll ans=0;
		if (n%3==0){
			n/=3;
			if (n==1)ans+=3;
			else{ans+=f[3][n%4];}
			For(w,1,m-1){
				n-=bin[w-1];	ll t=(n-1)/bin[w]+1;
				if (n<=0)break;
				if (t==1){
					ans+=bin[w]*3;
				}
				if (t==2){
					ans+=bin[w]*0;
				}
				if (t>2){
					ans+=bin[w]*f[3][t%4];
				}
			}
		}
		else if (n%3==1){
			n/=3;	++n;
			if (n==1)ans++;
			else{ans+=f[1][n%4];}
			For(w,1,m-1){
				n-=bin[w-1];	ll t=(n-1)/bin[w]+1;
				if (n<=0)break;
				if (t==1){
					ans+=bin[w]*1;
				}
				if (t==2){
					ans+=bin[w]*0;
				}
				if (t>2){
					ans+=bin[w]*f[1][t%4];
				}
			}
		}
		else if (n%3==2){
			n/=3;	++n;
			if (n==1)ans+=2;
			else{ans+=f[2][n%4];}
			For(w,1,m-1){
				n-=bin[w-1];	ll t=(n-1)/bin[w]+1;
				if (n<=0)break;
				if (t==1){
					ans+=bin[w]*2;
				}
				if (t==2){
					ans+=bin[w]*0;
				}
				if (t>2){
					ans+=bin[w]*f[2][t%4];
				}
			}
		}
		cout<<ans<<endl;
	}
}