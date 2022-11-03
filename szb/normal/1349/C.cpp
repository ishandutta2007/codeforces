#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
const ll N=1010;
pa q[N*N];
char s[N];
ll a[N][N],f[N][N],he,ta,n,m,t;
int main(){
	n=read();	m=read();	t=read();
	For(i,1,n){
		scanf("%s",s+1);
		For(j,1,m)	a[i][j]=s[j]-'0'+2;
	}
	For(i,1,n)For(j,1,m){
		bool fl=0;
		fl|=a[i-1][j]==a[i][j];
		fl|=a[i+1][j]==a[i][j];
		fl|=a[i][j-1]==a[i][j];
		fl|=a[i][j+1]==a[i][j];
		if (fl)	f[i][j]=0,q[++ta]=mk(i,j);
		else	f[i][j]=-1;
	}
	while(he<ta){
		ll x=q[++he].fi,y=q[he].se;
		if (x>1&&f[x-1][y]==-1)	f[x-1][y]=f[x][y]+1,q[++ta]=mk(x-1,y);
		if (x<n&&f[x+1][y]==-1)	f[x+1][y]=f[x][y]+1,q[++ta]=mk(x+1,y);
		if (y>1&&f[x][y-1]==-1)	f[x][y-1]=f[x][y]+1,q[++ta]=mk(x,y-1);
		if (y<m&&f[x][y+1]==-1)	f[x][y+1]=f[x][y]+1,q[++ta]=mk(x,y+1);
	}
	for(;t--;){
		ll x=read(),y=read(),tt=read();
		if (f[x][y]==-1)		cout<<a[x][y]-2<<endl;
		else if (f[x][y]>=tt)	cout<<a[x][y]-2<<endl;
		else					cout<<((a[x][y]-2)^((tt-f[x][y])&1))<<endl;
	}
}