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
const int N=55;
int gay,jud;
int a[N][N],match[N],dq[N],f[N<<1],Q[N][N],fir;
char ch[5];
bool cmp(int x,int y){
	return (a[gay][x]>a[gay][y])^jud;
}
int main(){
	int T=read();
	while(T--){
		int n=read();
		For(i,1,n)For(j,1,n)a[i][j]=read();
		cout<<"B"<<endl;
		cin>>ch>>fir;
		jud=(ch[0]=='D')^(fir<=n); 
		queue<int> q;
		memset(match,0,sizeof(match));
		For(i,1,n){q.push(i); gay=i; For(j,1,n)Q[i][j]=j; sort(&Q[i][1],&Q[i][n+1],cmp); dq[i]=1;}
		while(q.size()){
			int id=q.front(); q.pop();
			while(1){
				int t=Q[id][dq[id]++]; //if(t)cout<<id<<" "<<t<<endl;
				if(!match[t]||((a[match[t]][t]>a[id][t])^jud)){if(match[t])q.push(match[t]); match[t]=id; break;}
			}
		}
		For(i,1,n){f[i+n]=match[i]; f[match[i]]=i+n;}
		cout<<f[fir]<<endl;
		while(1){
			int t=read();
			if(t==-1)break; if(t==-2)return 0;
			cout<<f[t]<<endl;
		}
	}
}