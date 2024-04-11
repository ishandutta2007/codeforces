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
const ll N=600010,mod=1e9+7;
bool operator <(pa a,pa b){
	return a.fi<b.fi;
}
multiset<ll> q1;
multiset<ll>::iterator it;
priority_queue<ll,vector<ll>,greater<ll> > q2;
ll n,p,t[N],id[N],ans[N],q[N],he,ta;
bool cmp(ll a,ll b){
	if (t[a]==t[b])return a<b;
	return t[a]<t[b];
}
int main(){
	n=read();	p=read();
	For(i,1,n)t[i]=read(),id[i]=i;
	sort(id+1,id+n+1,cmp);
	ll pos=0,now=0;
	for(;;){
		if (he==ta){
			if (ta==n)break;
			++pos;
			now=t[id[pos]];
			q[++ta]=id[pos];
			q1.insert(id[pos]);
		}
		
		ll x=q[++he],cur=x;
		ans[x]=now+p;	now+=p;
		it=q1.lower_bound(x);
		q1.erase(it);
		
		for(;(pos<n)&&(t[id[pos+1]]<=now);){
			it=q1.begin();
			if (((it!=q1.end())&&((*it)<id[pos+1]))||(cur<id[pos+1])){
				++pos;
				q2.push(id[pos]);
			}else{
				++pos;
				q1.insert(id[pos]);
				q[++ta]=id[pos];
			}
		}
		
		for(;(!q2.empty())&&((he==ta)||((q2.top()<(*q1.begin()))));){
			x=q2.top();	q2.pop();
			q[++ta]=x;
			q1.insert(x);
		}
		
	}
	For(i,1,n)write(ans[i]),putchar(' ');
}
/*

5 314
0 310 942 628 0

*/