#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<int>
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
const int N=1005,inf=1e9;
int a[N];
poly mk(int l,int r){
	poly a; For(i,l,r)a.pb(i); return a;
}
char ask(poly a,poly b){
	cout<<"? "<<a.size()<<" "<<b.size()<<endl; 
	for(auto i:a)wri(i); puts("");
	for(auto i:b)wri(i); cout<<endl;
	string s;
	cin>>s;
	if(s[0]=='F')return '>';
	else if(s[0]=='S')return '<';
	return '=';
}
int find(int l,int r){
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(ask(mk(1,mid-l+1),mk(l,mid))=='=')return find(mid+1,r);
	else return find(l,mid);
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int T=read();
	while(T--){
		int n=read(),k=read();
		For(i,1,n-1)a[i]=i+1;
		random_shuffle(a+1,a+n);
		int f=0;
		For(i,1,min(n-1,30))if(ask({1},{a[i]})=='<'){cout<<"! 1"<<endl; f=1; break;}
		if(!f){
			for(int i=2;;i<<=1){
				if(i>n){
					cout<<"! "<<find(i/2+1,n)<<endl; break;
				}else{
					char t=ask(mk(1,i/2),mk(i/2+1,i));
					if(t!='='){
						if(t=='<')cout<<"! 1"<<endl; 
						else cout<<"! "<<find(i/2+1,i)<<endl;
						break;
					}
				}
			}
		}
	}
}