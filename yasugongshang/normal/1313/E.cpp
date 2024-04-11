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
char s[N<<1],t[N<<1],a[N],b[N];
int n,m,ls[N<<1],lt[N<<1],la[N],lb[N];
void getlcp(char ch[],int lcp[]){
	for(int i=2,l=1,r=1;i<=m;i++){
		lcp[i]=r>=i?min(lcp[i-l+1],r-i+1):0;
		while(ch[i+lcp[i]]==ch[1+lcp[i]])lcp[i]++;
		if(i+lcp[i]-1>r)r=i+lcp[i]-1,l=i;
	}
}
void exkmp(char a[],int res[],char b[],int lcp[]){
	for(int i=1,l=1,r=1;i<=n;i++){
		res[i]=r>=i?min(lcp[i-l+1],r-i+1):0;
		while(a[i+res[i]]==b[1+res[i]])res[i]++;
		if(i+res[i]-1>r)r=i+res[i]-1,l=i;
	}
}
struct bit{
	ll c[N];
	#define lowbit(i) i&-i
	void change(int p,int q){
		if(!p)return;
		for(int i=p;i<N;i+=lowbit(i))c[i]+=q;
	}
	ll ask(int p){
		ll ans=0; p=min(p,N-1);
		for(int i=p;i;i-=lowbit(i))ans+=c[i];
		return ans;
	}
}T1,T2;
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	n=read(),m=read();
	scanf("%s%s%s",a+1,b+1,s+1);
	memcpy(t,s,sizeof(s));
	reverse(t+1,t+m+1);  s[m]=t[m]='#';
	getlcp(s,ls);
	getlcp(t,lt);
	exkmp(a,la,s,ls);
	reverse(b+1,b+n+1);
	exkmp(b,lb,t,lt);
	reverse(lb+1,lb+n+1);
	ll ans=0;
	//For(i,1,n)cout<<la[i]<<" "<<lb[i]<<" "<<ls[i]<<endl;
	Rep(i,n,1){
		T1.change(lb[i],lb[i]);
		T2.change(lb[i],1);
		if(i+m-1<=n){
			T1.change(lb[i+m-1],-lb[i+m-1]);
			T2.change(lb[i+m-1],-1);
		}
		ans+=T1.ask(N-1)-T1.ask(m-la[i]-1)+(ll)(T2.ask(N-1)-T2.ask(m-la[i]-1))*(la[i]+1-m);
		//cout<<T1.ask(N-1)-T1.ask(m-la[i]-1)<<" fjz "<<T2.ask(N-1)<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
}