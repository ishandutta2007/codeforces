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
const ll N=300010;
ll A[N],n,k,ans;
struct dt{ll a,b,c;};
bool operator <(dt a,dt b){return a.c<b.c;}
bool operator >(dt a,dt b){return a.c>b.c;}
priority_queue<dt> q;
ll calc(ll x,ll t){
	ll a=x/t;
	return a*a*(t-x%t)+(a+1)*(a+1)*(x%t);
}
int main(){
	n=read();	k=read();
	For(i,1,n){
		A[i]=read();
		ans+=A[i]*A[i];
		if (A[i]!=1){
			q.push((dt){A[i],2ll,calc(A[i],1)-calc(A[i],2)});
		}	
	}
	while(n<k){
		--k;	dt tmp=q.top();	q.pop();
		ans-=tmp.c;
		if (tmp.a!=tmp.b)
			q.push((dt){tmp.a,tmp.b+1,calc(tmp.a,tmp.b)-calc(tmp.a,tmp.b+1)});
	}
	cout<<ans<<endl;
}