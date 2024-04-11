#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int N=100005;
priority_queue<pair<int,int> > q;
int n,m,k,p,b[N],h[N],a[N];
bool check(ll x){
	int sum=0;
	while(q.size())q.pop();
	for(int i=1;i<=n;i++){
		b[i]=0; q.push(mp(m-x/a[i],i));
	}
	for(int i=m;i;i--){
		if(q.top().first>=i)return 0;
		for(int j=0;j<k;j++){
			if(q.top().first<=0){
				sum+=k-j; break;
			}
			int t=q.top().second;
			q.pop();
			b[t]++;
			q.push(mp(m-(x+b[t]*p)/a[t],t));
		}
	}
	for(int i=1;i<=n;i++)if(h[i]>=x+b[i]*p-a[i]*m)sum-=(h[i]-(x+b[i]*p-a[i]*m)+p-1)/p;
	return sum>=0;
}
signed main(){
	n=read(); m=read(); k=read(); p=read();
	for(int i=1;i<=n;i++){
		h[i]=read(); a[i]=read();
	}
	//cout<<check(10)<<endl; return 0;
	ll l=0,r=1e14+1e9;
	while(l<r){
		ll mid=(l+r)>>1; //cout<<l<<" "<<r<<endl;
		if(check(mid))r=mid; else l=mid+1;
	}
	cout<<l<<endl;
}