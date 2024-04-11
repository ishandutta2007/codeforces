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
const int N=500005;
void GG(){
	puts("IMPOSSIBLE"); exit(0);
}
ll a[N],b[N];
int n;
string ans,sss;
ll sum;
void check(){
	int f=0;
	For(i,1,n)if(a[i]!=b[i])f=1;
	if(f){
		For(i,1,n)if(a[i]!=b[n-i+1])return;
		ans+='R';
	}
	int cnt=0;
	for(auto i:ans)if(i=='P')cnt++;
	reverse(ans.begin(),ans.end());
	if(cnt<=200000)cout<<"SMALL"<<endl<<ans.size()<<endl<<ans; 
	else cout<<"BIG"<<endl<<cnt<<endl; 
	exit(0);
}
void solve(){
	if(a[1]>a[2])swap(a[1],a[2]);
	if(b[1]>b[2])swap(b[1],b[2]);
	if(!b[1]||!b[2])GG();
	if(b[1]==a[1]&&b[2]%b[1]==a[2]%b[1]&&a[2]<=b[2]){
		sum+=(b[2]-a[2])/b[1]; b[2]=a[2]; cout<<"BIG"<<endl<<sum+200000<<endl; exit(0);
	}
	sum+=b[2]/b[1];
	b[2]%=b[1];
	solve();
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	n=read();
	For(i,1,n)a[i]=read();
	For(i,1,n)b[i]=read();
	For(i,0,10000000){
		check();
		if(i>=200000&&n==2)solve();
		if(n==1)GG();
		int f=1;
		For(i,1,n-1)if(b[i]>b[i+1])f=0;
		if(!f){
			ans+='R'; reverse(b+1,b+n+1);
		}
		ll sum=0;
		For(i,1,n){
			if(b[i]<=sum)GG();
			b[i]-=sum;
			sum+=b[i];
		}
		ans+='P';
	}
}