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
#define re resize
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
const int N=10005;
vector<int> v;
int ans[N];
int ask(int x,int y){
	cout<<"? "<<x<<" "<<y<<endl;
	cout<<"? "<<y<<" "<<x<<endl;
	int a,b;
	cin>>a>>b;
	if(a>b){
		swap(a,b); swap(x,y);
	}
	ans[y]=b;
	return x;
}
int main(){
	#ifdef Brollan
        //freopen("1.in","r",stdin);
    #endif
    int n=read();
    For(i,1,n)v.pb(i);
    while(v.size()>1){
    	vector<int> vv;
    	for(int i=0;i+1<v.size();i+=2){
    		vv.pb(ask(v[i],v[i+1]));
		}
		if(v.size()%2)vv.pb(v.back());
		swap(v,vv);
	}
	ans[v[0]]=n;
	cout<<"! "; For(i,1,n)wri(ans[i]); cout<<endl;
}