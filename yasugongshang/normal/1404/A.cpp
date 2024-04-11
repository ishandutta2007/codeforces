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
const int N=300005;
char ch[N];
int s[N][2];
int main(){
	#ifdef Brollan
        freopen("1.in","r",stdin);
    #endif
    int T=read();
    while(T--){
    	int n=read(),k=read(),f=1,c0=0,c1=0;
    	scanf("%s",ch+1);
    	For(i,0,k-1)mem(s[i]);
    	For(i,1,n)if(ch[i]!='?')s[i%k][ch[i]-'0']=1;
    	For(i,0,k-1)if(s[i][0]&&s[i][1])f=0;
    	For(i,0,k-1)if(s[i][0])c0++; else if(s[i][1])c1++;
    	if(c0>k/2||c1>k/2)f=0;
    	if(f)puts("YES"); else puts("NO");
	}
}