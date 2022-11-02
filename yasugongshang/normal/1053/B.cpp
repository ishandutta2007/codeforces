#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
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
inline void wri(ll a){write(a); putchar(' ');}
inline void writeln(ll a){write(a); puts("");}
const int N=300005;
int cal(ll x){
	return x==0?0:cal(x>>1)+(x&1);
}
int n,a[N],f[N],s[N][2];
ll ans;
signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=cal(read());
	}
	s[0][0]++;
	for(int i=1;i<=n;i++){
		int mx=0,sum=0;
		f[i]=(f[i-1]+a[i])%2;
		s[i][0]=s[i-1][0]; s[i][1]=s[i-1][1]; s[i][f[i]]++;
		for(int j=i;j&&j>i-70;j--){
			mx=max(mx,a[j]); sum+=a[j];
			if(sum%2==0&&mx*2<=sum)ans++;
		}
		if(i>70)ans+=s[i-71][f[i]];
	}
	cout<<ans<<endl;
}