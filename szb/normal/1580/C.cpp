#include<bits/stdc++.h>
using namespace std;
#define ll int
#define fi first
#define se second
#define y1 y1111111111111111111
#define pa pair<ll,ll>
#define mk make_pair
#define pb push_back
#define For(i,x,y)	for(ll i=(x);i<=(y);++i)
#define rep(i,x,y)	for(ll i=(x);i<(y);++i)
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if (ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return x*f;
}
void write(ll x){
	if (x<0)putchar('-'),x=-x;
	if (x>=10)write(x/10);
	putchar(x%10+'0');
}
const ll N=200010,cnt=500;
vector<ll>s[N],t[N];
ll x[N],y[N],sum[cnt+5][N],n,m;
void fafa(ll l,ll r,ll x,ll y){
	x=min(x,r-l+1);
	y=min(y,r-l+1-x);
	ll pos=l,t=(r-l)/(x+y);
	pos+=t*(x+y);
	for(;pos-x-y>r;)pos-=x+y;
	for(;pos<=r;)pos+=x+y;
	rep(t,0,x+y){
		if (t>=x){
			if (l<=m) 
			++sum[x+y][l];
			if (pos<=m)
			--sum[x+y][pos];
		}
		++l;
		++pos;
		if (pos-x-y>r)pos-=x+y; 
	}
}
void zoul(ll l,ll r,ll x,ll y){
	x=min(x,r-l+1);
	y=min(y,r-l+1-x); 
	for(ll i=l;i<=r;i+=x+y){
		ll a=i+x,b=min(r,i+x+y-1);
		if (a<=b){
			if (a<=m)
			++sum[1][a];
			if (b+1<=m)
			--sum[1][b+1];
		}
	}
}
int main(){
//	cout<<sizeof (sum)/1024/1024<<endl;
	n=read();	m=read();
	For(i,1,n)
		x[i]=read(),y[i]=read();
	For(i,1,m){
		ll opt=read(),k=read();
		if (opt==1){
			s[k].pb(i);
		}else{
			t[k].pb(i);
		}
	}
	For(i,1,n)if (s[i].size()!=t[i].size())t[i].pb(m+1);
	For(i,1,n)if (x[i]+y[i]<=cnt){
		rep(j,0,s[i].size()){
			ll l=s[i][j],r=t[i][j]-1;
			fafa(l,r,x[i],y[i]);
		}
	}else{
		rep(j,0,s[i].size()){
			ll l=s[i][j],r=t[i][j]-1;
			zoul(l,r,x[i],y[i]);
		}
	}
	For(i,1,cnt)For(j,i,m)sum[i][j]+=sum[i][j-i];
	For(i,1,m){
		ll ans=0;
		For(j,1,cnt)ans+=sum[j][i];
		write(ans);puts("");
	}
}
/*
3 4
10 15
12 10
1 1
1 3
1 1
2 1
2 3

*/