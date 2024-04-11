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
const int N=505;
map<int,map<char,vector<string> > > M;
string s;
int to[N];
vector<pair<string,string> > ans2,ans1;
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int n=read();
	to['a']=to['e']=to['i']=to['o']=to['u']=1;
	For(i,1,n){
		cin>>s;
		char alb;
		int cnt=0;
		for(auto i:s)if(to[i]){
			cnt++; alb=i;
		}
		M[cnt][alb].pb(s);
	}
	for(auto i:M){
		vector<string> an;
		for(auto j:i.se){
			for(int k=0;k+1<j.se.size();k+=2){
				ans2.pb(mp(j.se[k],j.se[k+1]));
			}
			if(j.se.size()&1)an.pb(j.se.back());
		}
		for(int k=0;k+1<an.size();k+=2)ans1.pb(mp(an[k],an[k+1]));
	}
	while(ans2.size()>ans1.size()){
		ans1.pb(ans2.back()); ans2.pop_back();
	}
	writeln(ans2.size());
	For(i,0,ans2.size()-1){
		cout<<ans1[i].fi<<" "<<ans2[i].fi<<"\n";
		cout<<ans1[i].se<<" "<<ans2[i].se<<"\n";
	}
}