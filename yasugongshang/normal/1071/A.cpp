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
ll a,b;
vector<int> ans1,ans2;
signed main(){
	cin>>a>>b;
	for(ll i=1;;i++)if(i*(i+1)/2>a+b){
		int t=i-1;
		for(int i=t;i;i--)if(a>=i){
			a-=i; ans1.push_back(i);
		}else{
			ans2.push_back(i);
		}
		cout<<ans1.size()<<endl;
		for(auto i:ans1)wri(i); puts("");
		cout<<ans2.size()<<endl;
		for(auto i:ans2)wri(i); puts("");
		return 0;
	}
}