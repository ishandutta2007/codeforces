#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
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
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=100005;
vector<PI> v[N];
ll a[N];
int tot,op[N],pos[N],b[N];
PI mx[N];
struct data{
	int a; ll b; int id;
}q[N];
bool cmp(data a,data b){
	return a.a*b.b>a.b*b.a;
}
bool cnm(data a,data b){
	return op[a.id]<op[b.id];
}
int main(){
	int k=read(),n=read(),m=read();
	For(i,1,k)a[i]=read();
	For(i,1,n){
		op[i]=read()-1; pos[i]=read(); b[i]=read();
		if(!op[i])mx[pos[i]]=max(mx[pos[i]],mp(b[i],i));
	}
	For(i,1,k)if(mx[i].fi>a[i])v[i].pb(mp(mx[i].fi-a[i],mx[i].se));
	//For(i,1,k)cout<<mx[i].fi<<endl;
	For(i,1,n)if(op[i]){
		if(op[i]==1)v[pos[i]].pb(mp(b[i],i));
		else q[++tot]=(data){b[i]-1,1,i};
	}
	For(i,1,k){
		sort(v[i].begin(),v[i].end()); reverse(v[i].begin(),v[i].end());
		for(auto j:v[i]){q[++tot]=(data){j.fi,a[i],j.se}; a[i]+=j.fi;}
	}
	sort(q+1,q+tot+1,cmp);
	//For(i,1,tot)cout<<q[i].a<<" "<<q[i].b<<" fjzzq "<<q[i].id<<endl;
	m=min(m,tot);
	cout<<m<<endl;
	sort(q+1,q+m+1,cnm);
	For(i,1,m)wri(q[i].id);
}