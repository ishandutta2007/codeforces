#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
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
const int N=16,M=2003;
int sum,a[N],b[N],dq;
bitset<M> dp[1<<N|2];
int main(){
	int n=read(),k=read();
	For(i,0,n-1)sum+=(a[i]=read());
	dp[0][0]=1;
	For(i,0,(1<<n)-1){
		for(int j=sum/k*k,o=sum/k;j;j-=k,o--)dp[i][o]=dp[i][o]|dp[i][j];
		For(j,0,n-1)if(!(i>>j&1)){
			dp[i|(1<<j)]|=dp[i]<<a[j];
		}
		//For(j,0,sum)if(dp[i][j])cout<<i<<" "<<j<<endl;
	}
	if(!dp[(1<<n)-1][1]){
		puts("NO"); return 0;
	}else puts("YES");
	int zt=(1<<n)-1,su=1;
	while(zt){
		if(su*k<=sum&&dp[zt][su*k]){
			su*=k; dq++;
		}else{
			For(i,0,n-1)if(zt>>i&1&&su>=a[i]&&dp[zt^(1<<i)][su-a[i]]){
				b[i]=dq; su-=a[i]; zt^=1<<i; break;
			}
		}
	}
	priority_queue<PI> q;
	For(i,0,n-1)q.push(mp(b[i],a[i]));
	while(q.size()>1){
		PI a=q.top(); q.pop(); PI b=q.top(); q.pop();
		int x=a.fi,y=a.se+b.se;
		cout<<a.se<<" "<<b.se<<endl;
		while(y%k==0){x--; y/=k; }
		q.push(mp(x,y));
	}
	
}