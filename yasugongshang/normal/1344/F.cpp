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
const int N=2005;
const char ycl[4]={'.','R','Y','B'};
bitset<N> a[N],ans;
bool A[N>>1][2][2];
string ch;
int m;
int main(){
	int n=read(),k=read();
	For(i,0,n-1)A[i][0][0]=A[i][1][1]=1;
	while(k--){
		cin>>ch; int t=read();
		if(ch=="mix"){
			while(t--){
				int p=read()-1;
				For(j,0,1)For(o,0,1)a[m+j][p<<1|o]=A[p][j][o];
			}
			cin>>ch;
			int re=0;
			if(ch=="W")re=0; else if(ch=="R")re=1; else if(ch=="Y")re=2; else re=3;
			a[m][2*n]=re&1;
			a[m+1][2*n]=re>>1;
			m+=2;
		}else{
			while(t--){
				int p=read()-1;
				if(ch=="RY")swap(A[p][0],A[p][1]);
				else {
					int t=ch=="RB";
					For(j,0,1)A[p][t][j]^=A[p][t^1][j];
				}
			}
		}
	}
	int dq=0;
	For(i,0,2*n-1){
		For(j,dq,m)if(a[j][i]){
			swap(a[j],a[dq]); break;
		}
		if(!a[dq][i])continue;
		For(j,dq+1,m)if(a[j][i])a[j]^=a[dq];
		dq++;
	}
	Rep(i,m-1,0){
		int jb=-1,sum=a[i][2*n];
		Rep(j,2*n-1,i)if(a[i][j]){
			sum^=a[i][j]&ans[j]; jb=j;
		}
		if(jb>=0)ans[jb]=sum; else if(sum){puts("No"); exit(0);}
	}
	puts("Yes");
	For(i,0,n-1)putchar(ycl[ans[2*i]+(int)ans[2*i+1]*2]);
}