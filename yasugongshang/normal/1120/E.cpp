#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define ull unsigned long long
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
const int M=5005;
bool vis[1005][M<<1];
int fr[1005][M<<1][3];
int main(){
	int a=read();
	queue<PI> q;
	q.push(mp(0,M));
	while(q.size()){
		int dq=q.front().first,cha=q.front().second; q.pop(); 
		for(int i=dq==0&&cha==M;i<10;i++){
			int xdq=(dq+i*a)/10,dig=(dq+i*a)%10;
			int xcha=cha+i-dig*a; 
			if(xcha<0||xcha>=2*M)continue;
			if(vis[xdq][xcha])continue;
			vis[xdq][xcha]=1;
			fr[xdq][xcha][0]=dq; fr[xdq][xcha][1]=cha; fr[xdq][xcha][2]=i; q.push(mp(xdq,xcha));
		}
	}
	if(!vis[0][M]){
		puts("-1"); return 0;
	}
	int x=0,y=M;
	vector<int> ans;
	while(1){
		ans.push_back(fr[x][y][2]);
		int nx=fr[x][y][0]; y=fr[x][y][1]; x=nx;
		if(x==0&&y==M)break;
	}
	reverse(ans.begin(),ans.end()); while(ans.size()&&*ans.rbegin()==0)ans.pop_back();
	reverse(ans.begin(),ans.end()); for(auto i:ans)write(i);
}