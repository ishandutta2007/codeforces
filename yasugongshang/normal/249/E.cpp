#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
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
const ll Mod[2]={10000000000,10000000007};
ll mod;
inline long long cheng(long long x,long long y)
{
long long tmp=(x*y-(long long)((long double)x/mod*y+1.0e-8)*mod);
return tmp<0 ? tmp+mod : tmp;
}
inline long long cheng(long long x,long long y,ll mod)
{
long long tmp=(x*y-(long long)((long double)x/mod*y+1.0e-8)*mod);
return tmp<0 ? tmp+mod : tmp;
}
ll cal(ll n){
	ll t[3];
	t[0]=n; t[1]=n+1; t[2]=2*n+1;
	for(int i=2;i<=3;i++)for(int j=0;j<3;j++)if(t[j]%i==0){
		t[j]/=i; break;
	}
	ll ans=1;
	for(int i=0;i<3;i++)ans=cheng(ans,t[i]);
	return ans;
}
ll Cal(ll n){
	return cal(n-1)+n;
}
ll sum(ll n){
	if(n%2==0)return cheng(n/2,n+1); else return cheng(n,(n+1)>>1);
}
ll x1,Y1,x2,y2;
ll cal(ll x,ll y){
	ll t=sum(cheng(min(x,y),min(x,y),mod*2)),add;
	if(x<y){
		//cout<<Cal(y)-Cal(x)<<endl;
		add=cheng(sum(x-1),y-x)+cheng(Cal(y)-Cal(x),x);
	}else{
		add=-cheng(sum(y-1),x-y)+cheng(cal(x)-cal(y),y);
	}
	return ((t+add)%mod+mod)%mod;
}
int main(){
	//mod=Mod[0]; cout<<cal(1,3)<<endl; return 0;
	int T=read();
	
	while(T--){
		ll x1=read(),Y1=read(),x2=read(),y2=read();
		x1--; Y1--;
		mod=Mod[0];
		ll ans1=cal(x2,y2)+cal(x1,Y1)-cal(x2,Y1)-cal(x1,y2);
		ans1=(ans1%mod+mod)%mod;
		mod=Mod[1];
		ll ans2=cal(x2,y2)+cal(x1,Y1)-cal(x2,Y1)-cal(x1,y2);
		ans2=(ans2%mod+mod)%mod;
		if(ans1!=ans2){
			for(int i=0;i<3;i++)putchar('.');
			ll dq=1;
			for(int j=1;j<10;j++){
				dq*=10;
				if(ans1<dq)putchar('0');
			}
			writeln(ans1);
		}else{
			writeln(ans1);
		}
	}
}