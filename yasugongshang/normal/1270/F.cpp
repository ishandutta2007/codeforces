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
const int N=200005,B=200;
char ch[N];
ll ans;
int to[N],s[N],S[N],q[N];
int ask(int x,int y){
	int t=y/x;
	return max(0,t-B);
}
int main(){
	scanf("%s",ch+1);
	int n=strlen(ch+1);
	For(i,1,n)s[i]=s[i-1]+(ch[i]-='0');
	For(i,1,B){
		q[0]=0;
		For(j,1,n){
			q[j]=q[j-1]+ch[j]*i-1;
			//if(i==2)cout<<q[j]<<" "<<(int)ch[j]<<endl;
		}
		sort(q,q+n+1);
		for(int j=0,k=0;j<=n;j=k){
			while(k<=n&&q[j]==q[k])k++;
			ans+=(ll)(k-j)*(k-j-1)/2;
		}//if(i<=5)cout<<i<<" "<<ans<<endl;
	}
	Rep(i,n,0)to[s[i]]=i;
	For(i,1,n){
		For(j,1,n/B)if(s[i]>=j){
			ans+=ask(j,i-to[s[i]-j])-ask(j,i-to[s[i]-j+1]);
		}
	}
	cout<<ans<<endl;
}