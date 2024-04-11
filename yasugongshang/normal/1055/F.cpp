#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
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
const int N=1000005;
ll dq,ans,b[N],w[N],q[N],k;
int n;
void bao(int x){
	ll dd=dq^((ll)1<<x);
	for(int j=1,l,r;j<=n;j=r){
		l=r=j+1;
		while(l<=n&&(b[l]&dq)==(b[j]&dq))l++;
		while(r<=n&&(b[r]&dd)==(b[j]&dd))r++;
		int jb=j;
		for(int k=l;k<r;k++)q[jb++]=b[k];
		for(int k=j;k<l;k++)q[jb++]=b[k];
		for(int k=j;k<r;k++)b[k]=q[k];
	}
}
int main(){
	n=read(); k=read();
	for(int i=2;i<=n;i++){
		int fa=read(); w[i]=read()^w[fa];
	}
	sort(&w[1],&w[n+1]);
	for(int i=1;i<=n;i++)b[i]=w[i];
	for(int i=61;i>=0;i--){
		dq|=(ll)1<<i; 
		ll sum=0;
		int l=1,r=1;
		for(int j=1;j<=n;j++){
			ll t=(b[j]^ans)&dq;
			while(l<=n&&(w[l]&dq)<t)l++;
			while(r<=n&&(w[r]&dq)<=t)r++;
			sum+=r-l;
		}
		//cout<<i<<" "<<sum<<endl;
		if(sum<k){ans|=(ll)1<<i; bao(i); k-=sum;}
	}
	cout<<ans<<endl;
}