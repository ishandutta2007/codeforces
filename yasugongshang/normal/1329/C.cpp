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
const int N=1<<21|2;
int a[N],p[N>>1],to[N>>1],h,g;
void f(int p){
	int l=p<<1,r=p<<1|1;
	if(!a[l]&&!a[r]){
		a[p]=0; return;
	}
	if(a[l]>a[r]){
		to[a[p]=a[l]]=p; f(l);
	}else{
		to[a[p]=a[r]]=p; f(r);
	}
}
bool check(int p){
	//cout<<p<<endl;
	int l=p<<1,r=p<<1|1;
	if(!a[l]&&!a[r]){
		return p>=(1<<g);
	}
	if(a[l]>a[r]){
		return check(l);
	}else{
		return check(r);
	}
	
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int T=read();
	while(T--){
		h=read(),g=read();
		For(i,1,(1<<(h+1))-1)a[i]=0;
		For(i,1,(1<<h)-1){
			a[i]=read(); p[i]=a[i]; to[a[i]]=i;
		}
		vector<int> ans;
		sort(p+1,p+(1<<h),cmp);
		For(i,1,(1<<h)-1){
			if(check(to[p[i]])){
				ans.pb(to[p[i]]);
				f(to[p[i]]);
			}
		}
		ll sum=0;
		For(i,1,(1<<g)-1)sum+=a[i];
		writeln(sum);
		for(auto i:ans)wri(i); puts("");
	}
}
/*
1
3 2
100 11 11 6 6 5 4 

*/