#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
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
inline ull rnd(){
	ull ans=0;
	For(i,0,5)ans=ans<<15^rand();
	return ans;
}
const int N=3005;
const ld pi=acos(-1);
PI a[N],b[N<<1];
ll cha(PI a,PI b){
	return (ll)a.fi*b.se-(ll)a.se*b.fi;
}
int chu(PI a){
	if(a.se>0||a.se==0&&a.fi>0)return 0;
	else return 1;
}
bool cmp(PI a,PI b){
	int A=chu(a),B=chu(b);
	return A!=B?A<B:cha(a,b)>0;
}
signed main(){
	int n=read();
	For(i,1,n){
		a[i].fi=read(); a[i].se=read();
	}
	ll ans=0;
	For(i,1,n){
		int tot=0;
		For(j,1,n)if(i!=j){
			tot++;
			b[tot].fi=a[j].fi-a[i].fi;
			b[tot].se=a[j].se-a[i].se;
		}
		sort(b+1,b+tot+1,cmp);
		For(j,1,tot)b[tot+j]=b[j];
		int dq=1;
		For(j,tot+1,tot*2){
			dq=max(dq,j-tot+1);
			while(cha(b[j],b[dq])>0)dq++;
			//if(i==1)cout<<tot<<" "<<j<<" "<<dq<<" "<<b[j].fi<<" "<<b[j].se<<endl;
			ans+=(j-dq)*(j-dq-1)/2;
		}
		//cout<<i<<" "<<ans<<endl;
	} 
	//cout<<ans/2<<endl;
	ans=(ll)n*(n-1)*(n-2)/6*(n-3)-ans;
	cout<<ans*(n-4)/2<<endl;
}
/*
6
-1 1
0 0
1 0
2 1
1 2
0 2

*/