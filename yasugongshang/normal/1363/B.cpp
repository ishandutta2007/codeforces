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
const int N=100005;
char ch[N];
int s[N][2],t[N][2];
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int T=read();
	while(T--){
		scanf("%s",ch+1);
		int n=strlen(ch+1),ans=0;
		For(i,1,n){
			ch[i]-='0';
			For(j,0,1){
				s[i][j]=s[i-1][j]+(j==ch[i]);
			}
		}
		t[n+1][0]=t[n+1][1]=0;
		Rep(i,n,1){
			For(j,0,1){
				t[i][j]=t[i+1][j]+(j==ch[i]);
				//cout<<i<<" "<<j<<" "<<t[i][j]<< " "<<s[i-1][j^1]<<endl;
				ans=max(ans,t[i][j]+s[i-1][j^1]);
			}
			
		}
		cout<<n-ans<<endl;
	}
}