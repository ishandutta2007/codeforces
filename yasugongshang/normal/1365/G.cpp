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
const int N=1005;
int f[1<<13|2],tot,q[N];
ull ans[N];
ull ask(vector<int> v){
	if(!v.size())return 0;
	cout<<"? ";
	cout<<v.size()<<" ";
	for(auto i:v)cout<<i<<" "; cout<<endl;
	ull t;
	cin>>t; return t;
}

int main(){
	#ifdef Brollan
		//freopen("1.in","r",stdin);
	#endif
	int n=read();
	For(i,1,(1<<13)-1)f[i]=f[i>>1]+(i&1); 
	For(i,1,(1<<13)-1)if(f[i]==6&&tot<n){
		q[++tot]=i;
	}
	For(i,0,12){
		vector<int> v;
		For(j,1,tot)if(q[j]>>i&1)v.pb(j);
		ans[i]=ask(v);
	}
	cout<<"! ";
	For(i,1,n){
		ull t=0;
		For(j,0,12)if((q[i]>>j&1)==0)t|=ans[j];
		cout<<t<<" ";
	}
	cout<<endl;
}