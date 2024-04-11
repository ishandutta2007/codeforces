#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
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
const int N=1005;
int a[N];
vector<int> v[N];
bool ans[N][N];
int main(){
	int n=read();
	For(i,1,n)a[i]=read();
	For(i,0,a[1]-1){
		ans[i][1]=1;
		v[0].pb(i);
	}
	For(i,a[1],n)v[1].pb(i);
	For(i,2,n){
		int bj=0;
		For(j,0,i-1)if(v[j].size()>=2){
			int t=min(a[i],(int)v[j].size()-1);
			For(k,1,t){
				int zs=v[j].back();
				v[i].pb(zs);// cout<<zs<<endl;
				ans[zs][i]=1;
				v[j].pop_back();
			}
			bj=j; a[i]-=t; break;
		}
		For(j,0,i-1)if(j!=bj){
			int t=min(a[i],(int)v[j].size());
			For(k,0,t-1)ans[v[j][k]][i]=1;
			a[i]-=t;
		}
	}
	cout<<n+1<<endl;
	For(i,0,n){
		For(j,1,n)write(ans[i][j]); puts("");
	}
}