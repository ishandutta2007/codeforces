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
ll a[5],x,y,z;
void gan(ll t){
	cout<<t<<endl;
	a[read()-1]+=t;
}
bool cmp(int x,int y){
	return a[x]>a[y];
}
int ask(){
	int q[3];
	For(i,0,2)q[i]=i;
	sort(q,q+3,cmp);
	x=q[0]; y=q[1]; z=q[2];
}
int main(){
	#ifdef Brollan
		//freopen("1.in","r",stdin);
	#endif
	For(i,0,2)a[i]=read();
	cout<<"First"<<endl;
	ask();
	gan(a[x]);
	ask();
	gan(a[x]-a[y]+a[x]-a[z]);
	ask();
	gan(a[x]-a[y]);
}
/*
49 49,1

a,a
2a,a
3a,a
6a,a
7a,a
14a,a
a,b,3->a-b,b,1/a+a,b-a,2
a,b,2->a,b+a,3/a,b+b+a,3
a,b,1->a,b+b,3
*/