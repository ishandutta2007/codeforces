#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<int>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
#define x first
#define y second
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
const int N=100005,IN=1e5;
PI q[N<<3],Q[N<<3];
int top,tt;
ll cha(PI a,PI b){
	return a.x*b.y-a.y*b.x;
}
PI operator -(PI a,PI b){
	return mp(a.x-b.x,a.y-b.y);
}
ld solve(PI a,PI b,PI c){
	ld A=2*(a.x-b.x),B=2*(a.y-b.y),C=a.x*a.x+a.y*a.y-b.x*b.x-b.y*b.y;
	ld D=2*(a.x-c.x),E=2*(a.y-c.y),F=a.x*a.x+a.y*a.y-c.x*c.x-c.y*c.y;
	ld Y=(C*D-F*A)/(B*D-E*A),X=a.x!=b.x?(C-B*Y)/A:(F-E*Y)/D; 
	return sqrt((a.x-X)*(a.x-X)+(a.y-Y)*(a.y-Y));
}//(2x1-2x2)a+(2y1-2y2)b=x1^2-x2^2+y1^2-y2^2
bool cmp(PI a,PI b){
	ll t=cha(a-q[1],b-q[1]);
	return t==0?abs(a.x-q[1].x)+abs(a.y-q[1].y)<abs(b.x-q[1].x)+abs(b.y-q[1].y):t>0;
}
int main(){
	int n=read(),tt=0;
	For(i,1,n){
		int x=read(),y=read(),v=read();
		if(x+v<=IN){
			q[++tt]=mp(x+v,y);
		}else{
			if(y-(x+v-IN)>0)q[++tt]=mp(IN,y-(x+v-IN)); else q[++tt]=mp(IN,0);
			if(y+(x+v-IN)<IN)q[++tt]=mp(IN,y+(x+v-IN)); else q[++tt]=mp(IN,IN);
		}
		if(x-v>=0){
			q[++tt]=mp(x-v,y);
		}else{
			if(y-(v-x)>0)q[++tt]=mp(0,y-(v-x)); else q[++tt]=mp(0,0);
			if(y+(v-x)<IN)q[++tt]=mp(0,y+(v-x)); else q[++tt]=mp(0,IN);
		}
		if(y+v<=IN){
			q[++tt]=mp(x,y+v);
		}else{
			if(x-(y+v-IN)>0)q[++tt]=mp(x-(y+v-IN),IN); 
			if(x+(y+v-IN)<IN)q[++tt]=mp(x+(y+v-IN),IN); 
		}
		if(y-v>=0){
			q[++tt]=mp(x,y-v);
		}else{
			if(x-(v-y)>0)q[++tt]=mp(x-(v-y),0); 
			if(x+(v-y)<IN)q[++tt]=mp(x+(v-y),0);
		}
	}
	For(i,2,tt)if(q[i]<q[1])swap(q[1],q[i]);
	sort(q+2,q+tt+1,cmp);
	//For(i,1,tt)cout<<q[i].x<<" "<<q[i].y<<endl;
	Q[top=0]=q[1];
	For(i,2,tt){
		while(top>=1&&cha(Q[top]-Q[top-1],q[i]-Q[top])<=0)top--;
		Q[++top]=q[i];
	}
	top++;
	ld mx=-1; int pos;
	For(i,0,top-1){
		ld t=solve(Q[i],Q[(i+1)%top],Q[(i+2)%top]);
		if(t>mx){
			mx=t; pos=i;
		}
	}//cout<<top<<endl;
	For(i,0,2)wri(Q[(pos+i)%top].x),writeln(Q[(pos+i)%top].y);
}
/*
3
0 80 0
80 0 0
100000 0 0

*/