#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
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
const int N=300005;
#define lowbit(i) i&-i
struct data{
	int x,y,id;
}a[N];
int c[N<<1],dp[N];
bool cmpy(data a,data b){
	return a.y>b.y;
}
inline int get(int pos){
	int ans=0;
	for(int i=pos;i;i-=lowbit(i))ans=max(ans,c[i]);
	return ans;
}
inline void change(int pos,int de){
	for(int i=pos;i<N*2;i+=lowbit(i))c[i]=max(c[i],de);
}
vector<int> solve(int n){ 
	sort(&a[1],&a[n+1],cmpy);
	//For(i,1,n)cout<<a[i].x<<" fjzzq "<<a[i].y<<endl;
	int ans=0;
	memset(c,0,sizeof(c));
	For(i,1,n){
		if(a[i].x>a[i].y)continue;
		//cout<<a[i].x<<" "<<a[i].y<<" "<<get(2*n-a[i].x+1)<<endl;
		dp[i]=get(2*n-a[i].x+1)+1;
		change(2*n-a[i].y+1,dp[i]);
		ans=max(ans,dp[i]);
	}
	int dq=0;
	vector<int> v;
	Rep(i,n,1)if(a[i].x<a[i].y&&a[i].y>dq&&dp[i]==ans){
		//cout<<dq<<" "<<a[i].id<<endl;
		dq=a[i].x; ans--; v.pb(a[i].id);
	}
	reverse(v.begin(),v.end());
	return v;
}
int main(){
	int n=read();
	For(i,1,n){a[i].x=read(); a[i].y=read(); a[i].id=i;}
	vector<int> A=solve(n); 
	For(i,1,n){a[i].x=2*n+1-a[i].x; a[i].y=2*n+1-a[i].y;}
	vector<int> B=solve(n);
	if(B.size()>A.size())A=B;
	cout<<A.size()<<endl;
	for(auto i:A)wri(i);
}