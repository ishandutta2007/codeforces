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
const int N=105;
int tot,ans[N],X[N],Y[N],a[N],to[2000005];
void cz(int p){
	cout<<"+ "<<p<<endl;
	tot++; 
	X[tot]=read(); Y[tot]=read();
}
int main(){
	int n=read();
	For(i,2,n+1){
		a[i]=i*(i-1)*(i-2)/6;
		to[a[i]-a[i-1]]=i-1;
	}
	X[0]=read(); Y[0]=read();
	if(n>=5)cz(n-1);
	Rep(i,n-2,4)cz(i);
	cz(3); cz(1); cz(2); cz(1);
	Rep(i,n,1){
		X[i]-=X[i-1]; Y[i]-=Y[i-1]; 
	}
	if(X[n-4+2])ans[1]=to[X[n-4+2]];
	else if(X[n-4+4])ans[1]=1;  //cout<<ans[1]<<" "<<X[n-4+2]<<endl;
	ans[3]=Y[n-4+4]-Y[n-4+2]-1;
	ans[2]=Y[n-4+2]/(ans[3]+1); 
	ans[4]=Y[n-4+3]/(ans[3]+1)-ans[1]-1;//cout<<Y[n-4+3]<<" "<<ans[3]<<" "<<ans[1]<<" "<<ans[4]<<endl;
	if(n>=5)ans[5]=(Y[n-4+1]-ans[1]*ans[2]-ans[2]*ans[4])/ans[4];
	For(i,4,n-2){
		ans[i]--;
		ans[i+2]=(Y[n-i]-ans[i-1]*ans[i-2]-ans[i-1]*ans[i+1])/ans[i+1];
	}
	if(n>=5)ans[n-1]--;
	cout<<"! ";
	For(i,1,n)wri(ans[i]); cout<<endl;
}
/*
5
0 0
0 0
0 1
0 2
0 4 
0 6 
 
*/