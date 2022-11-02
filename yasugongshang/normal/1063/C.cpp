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
const int N=1000005;
string g,f;
signed main(){
	int n=read(); 
	cout<<"0 0"<<endl;
	cin>>f;
	int l=1,r=1e9;
	for(int i=1;i<n;i++){
		int mid=(l+r)>>1;
		cout<<mid<<" "<<mid<<endl;
		cin>>g;
		if(g==f)l=mid+1; else r=mid-1; 
	}
	l--;
	cout<<l<<" "<<l+1<<" "<<l+1<<" "<<l<<endl;
}