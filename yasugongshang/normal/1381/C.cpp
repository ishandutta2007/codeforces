#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<int>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
#define mem(a) (memset(a,0,sizeof(a)))
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
ll rnd(){
	ull ans=0;
	For(i,0,4)ans=ans<<15^rand();
	return ans%((ull)1<<63);
}
const int N=100005;
int n,x,y,a[N],ans[N];
vector<int> v[N];
priority_queue<PI> q; 
void gan(int x){
	For(i,0,x-1){
		a[i]=q.top().se; q.pop();
	}
	For(i,0,x-1){
		ans[v[a[i]].back()]=a[(i+1)%x];
		v[a[i]].pop_back(); 
		if(v[a[i]].size())q.push(mp(v[a[i]].size(),a[i]));
	}
	
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int T=read();
	while(T--){
		n=read(); x=read(); y=read();
		For(i,1,n+1){
			v[i].clear();  
		}
		For(i,1,n)v[a[i]=read()].pb(i);
		int jb=0;
		while(q.size())q.pop();
		For(i,1,n+1)if(v[i].size()){
			q.push(mp(v[i].size(),i));
		}else jb=i;
		For(i,1,n)ans[i]=jb;
		For(i,1,x){
			gan(1);
		}
		int fl=1;
		while(y>=x+2){
			if(q.size()>=y-x){
				gan(y-x); y=x; break;
			}
			if(q.size()<2){
				fl=0; break;
			}
			gan(2);
			y-=2;
		}
		if(y==x+1){
			if(q.size()>=2){
				int s=v[q.top().se].back(); q.pop();
				ans[s]=q.top().se;
			}
			else fl=0;
		}
		if(fl){
			puts("YES");
			For(i,1,n)wri(ans[i]); puts("");
		}else{
			puts("NO");
		}
	}
}
/*
11234

*/