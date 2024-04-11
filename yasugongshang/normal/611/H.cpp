#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
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
const int N=8;
int m,cnt[N],dq[N],e[N][N],ycl[N],vis[N];
vector<PI> ans;
void GG(){
	puts("-1"); exit(0);
}
bool check(){
	For(i,0,(1<<m)-2){
		int sum=0;
		For(j,0,m-1)if(i>>j&1)sum+=cnt[j];
		For(j,0,m-1){
			For(k,j,m-1)if((i>>j&1)||(i>>k&1))sum-=e[j][k];
		}
		if(sum>0)return 0;
	}
	return 1;
}
int main(){
	int n=read();
	For(i,1,n-1){
		string a,b;
		cin>>a>>b;
		int A=a.length()-1,B=b.length()-1;
		e[A][B]++; if(A!=B)e[B][A]++;
	}
	for(int i=n;i;i/=10)m++;
	For(i,ycl[0]=1,m)ycl[i]=ycl[i-1]*10; ycl[m]=n+1;
	vis[0]=1;
	For(i,0,m-1){cnt[i]=ycl[i+1]-ycl[i]; dq[i]=ycl[i];}
	//cout<<e[0][0]<<" "<<e[0][1]<<" "<<e[1][1]<<endl;
	if(!check())GG();
	cnt[0]--; dq[0]++;
	while(ans.size()<n-1){
		For(i,0,m-1)if(vis[i]){
			For(j,0,m-1)if(cnt[j]&&e[i][j]){
				e[i][j]--; if(i!=j)e[j][i]--;
				cnt[j]--;
				if(!check()){
					e[i][j]++; if(i!=j)e[j][i]++;
					cnt[j]++; continue;
				}else{
					vis[j]=1; 
					ans.pb(mp(ycl[i],dq[j]++));
				}
			}
		}
	}
	for(auto i:ans){wri(i.fi); writeln(i.se);}
}