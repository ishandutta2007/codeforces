#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define ull unsigned long long
#define mp make_pair
#define ld long double
#define fi first
#define se second
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
string an;
#define getchar gc
#define putchar(x) an+=x
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
inline void writeln(ll a){write(a); putchar('\n');}
inline void wri(ll a){write(a); putchar(' ');}
const int N=1000005;
int cs,n,m,hp[N],q[N],to[N],sum;
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)sum+=(hp[i]=read());
	cs=(sum+n-1)/n; hp[1]+=cs*n-sum;
	int dq=1,dd=0;
	//for(int i=1;i<=m;i++)wri(hp[i]); puts("");
	for(int i=1;i<=cs;i++){
		int zs=n; 
		while(zs){
			if(hp[dq]-dd>=zs){
				dd+=zs; zs=0;
			}else{
				//cout<<n-zs<<" "<<dq<<endl;
				//cout<<dq<<" "<<dd<<" "<<zs<<endl;
				zs-=hp[dq]-dd; q[++*q]=n-zs; dq++; dd=0;
			}
		}
	}
	writeln(cs);
	while(*q<=m)q[++*q]=n; //cout<<*q<<endl;
	sort(&q[1],&q[*q]);  //for(int i=1;i<*q;i++)cout<<q[i]<<" "; puts("");
	for(int i=1;i<*q;i++){to[q[i]]=i;wri(i>1?q[i]-q[i-1]:q[i]);} putchar('\n');
	dq=1,dd=0;
	for(int i=1;i<=cs;i++){
		int zs=n,las=0;
		while(zs){
			if(hp[dq]-dd>=zs){
				while(las<m){las++; wri(dq);}
				dd+=zs; zs=0;
			}else{
				zs-=hp[dq]-dd; int pos=to[n-zs];
				while(las<pos){las++; wri(dq);} 
				dq++; dd=0;
			}
		}putchar('\n');
	}
	cout<<an;
}
/*
13 7
5 2 1 5
4 8 11 5 7 8  
*/