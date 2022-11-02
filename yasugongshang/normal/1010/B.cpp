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
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=200005;
int n,m,t[N],tot;
signed main(){
	n=read(); m=read();
	for(int i=0;i<m;i++){
		cout<<1<<endl; fflush(stdout);
		t[i]=read(); if(t[i]==0)return 0;
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		cout<<mid<<endl; fflush(stdout);
		int x=read(); x*=t[tot]; tot=(tot+1)%m;
		if(x==0)return 0;
		if(x==-1)r=mid-1; else l=mid+1;
	}
}