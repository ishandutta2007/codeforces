#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
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
const int N=5000;
int a[N],p[N],ans[N],zyk[N],kk;
vector<int> v;
int ask(int s,int t){
	cout<<"? "<<s+1<<" "<<t+1<<endl;
	#ifdef Brollan
		return a[s]|a[t];
	#endif
	return read();
}
int ask(int x){
	int sum=2047;
	For(i,0,kk-1)if((zyk[i]&sum)<sum){
		if(x!=v[i])sum&=ask(x,v[i]); else sum&=zyk[i];
	}
	return sum;
}
int main(){
	#ifdef Brollan
		//freopen("1.in","r",stdin);
	#endif
	srand(time(0));
	int n=read();
	For(i,0,n-1)p[i]=i;
	random_shuffle(p,p+n);
	//For(i,0,n-1)a[i]=read();
	int alb=2047;
	while(alb){
		int a=rand()%n,b=rand()%n;
		if(a==b)continue;
		int t=ask(a,b);
		if((t&alb)<alb){
			alb&=t; v.pb(a); zyk[kk++]=t;
		}
	}
	int dq=ask(p[0]),pos=p[0];
	For(i,1,n-1){
		if(ask(pos,p[i])==dq){
			dq=ask(p[i]); pos=p[i];
		}
	}
	For(i,0,n-1)if(i==pos)ans[i]=0; else ans[i]=ask(pos,i);
	cout<<"! ";
	For(i,0,n-1)wri(ans[i]); cout<<endl;
}