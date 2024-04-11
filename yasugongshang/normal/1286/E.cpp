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
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=600005;
const ll P=1e18;
int q[N],Q[N],nxt[N],S,top;
char ch[N];
ull sum,ans;
ll a,b;
map<int,int> M;
char s[3];
vector<int> v[N];
int ask(int pos){
	return Q[lower_bound(q+1,q+top+1,pos)-q];
}
int main(){
	int n=read();
	For(i,0,n-1){
		scanf("%s",s); ch[i]=(s[0]-'a'+S)%26+'a';
		int w=read()^(ans&((1<<30)-1));
		//cout<<w<<endl;
		nxt[i]=i?nxt[i-1]:0;
		//cout<<M.size()<<" "<<w<<endl;
		if(i){
			while(ch[nxt[i]]!=ch[i]&&nxt[i]){v[i].pb(nxt[i]); nxt[i]=nxt[nxt[i]-1];}
			if(ch[nxt[i]]==ch[i]){for(auto j:v[nxt[i]])v[i].pb(j); nxt[i]++; }
			for(auto j:v[i]){
				int t=ask(i-j);
				M[t]--; sum-=t;
			}
		}
		if(ch[0]==ch[i]){M[w]++; sum+=w;}
		if(i){
			M[w]+=0;
			auto it=M.find(w),j=it; 
			for(j++;j!=M.end();M.erase(j++)){
				sum-=((ll)j->fi-w)*j->se;
				it->se+=j->se;
			}
		}
		//cout<<sum<<endl;
		while(top&&Q[top]>=w)top--;
		q[++top]=i; Q[top]=w;
		ans+=sum; S=(S+sum)%26;
		b+=sum; if(b>=P){a++; b-=P;}
		if(a){
			write(a); for(ll j=P/10;j>1;j/=10)if(b<j)putchar('0'); writeln(b);
		}else writeln(b);
	}
	//cout<<ch<<endl;
}
 
/*
11
x 944128304
v 11115075
r 494806706
d 833060203
c 65132746
q 608297596
f 687601150
v 343896891
q 901967764
f 534519373
g 348220995
*/