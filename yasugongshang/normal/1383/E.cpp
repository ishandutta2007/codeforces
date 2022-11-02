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
const int N=1000005,mod=1e9+7;
char ch[N];
ll dp[N];
int n,cnt;
PI q[N];
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	scanf("%s",ch+1);
	n=strlen(ch+1);
	ch[0]='1'; 
	int bbb=0,top=0;
	ll ans=0;
	For(i,1,n)if(ch[i]=='1')break; else bbb++;
	For(i,1,n){
		//to[ch[i]-'0']=i; 
		cnt++;
		if(ch[i]=='1'){
			if(i>cnt){
				while(top&&q[top].fi<=cnt){
					ans=(ans+(q[top-1].se-q[top].se+mod)*q[top].fi)%mod;
					top--;
				}
				//cout<<ans<<endl;
				ans=(ans+(dp[i-cnt]-q[top].se+mod)*cnt)%mod;
				//cout<<ans<<endl;
				q[++top]=mp(cnt,dp[i-cnt]);		
			}
			cnt=0;
			dp[i]=(ans+bbb+1)%mod;
			//cout<<dp[i]<<endl;
		}
	}
	Rep(i,n,0)if(i==0)cout<<n<<endl;
	else if(ch[i]=='1'){
		cout<<dp[i]*(n-i+1)%mod<<endl; break;
	}
}