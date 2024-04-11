#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
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
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=120000;
struct point{
	int x,y;
	point(int _x=0,int _y=0):x(_x),y(_y){}
};
bool operator <(point a,point b){
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
int q;
map<int,int> ans[N],MM[N];
map<ll,set<point> > M;
void insert(int x,int y,int id){
	int t=__gcd(x,y);
	x/=t; y/=t;
	ans[x][y]+=id;
}
int tot;
int main(){
	q=read();
	while(q--){
		int op=read(),x=read(),y=read();
		if(op==1){ 
			tot++;
			ll t=(ll)x*x+(ll)y*y;
			set<point> v=(M.find(t))->second;
			for(auto vv:v){
				insert(vv.x+x,vv.y+y,1);
			}
			M[t].insert((point){x,y});
			int tt=__gcd(x,y);
			x/=tt; y/=tt;
			MM[x][y]++;
		}else if(op==2){
			tot--;
			ll t=(ll)x*x+(ll)y*y;
			M[t].erase((point){x,y});
			set<point> v=(M.find(t))->second;
			for(auto vv:v){
				insert(vv.x+x,vv.y+y,-1);
			}
			int tt=__gcd(x,y);
			x/=tt; y/=tt;
			MM[x][y]--;
		}else{
			int t=__gcd(x,y); x/=t; y/=t;
			writeln((tot-MM[x][y])-2*ans[x][y]);
		}
	}
}