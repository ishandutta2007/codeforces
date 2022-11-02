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
const int N=33;
int n,m,ans,a[N][N],b[N];
signed main(){
	n=read(); 
	m=(n+1)>>1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)a[i][j]=read();
	}
	for(int i=0;i<(1<<m);i++){
		for(int j=0;j<m;j++)b[j]=i>>j&1;
		int sum=0;
		for(int j=0;j<m-1;j++){
			int s1=0,s2=0;
			for(int k=0;k<m-1;k++){
				s1+=abs(a[j][k]+(b[k]?-a[j+m][k]:a[j+m][k])+a[j][k+m]+((b[k]^b[m-1])?-a[j+m][k+m]:a[j+m][k+m]));
				s2+=abs(a[j][k]+(b[k]?-a[j+m][k]:a[j+m][k])-a[j][k+m]+((b[k]^b[m-1])?a[j+m][k+m]:-a[j+m][k+m]));
			}
			s1+=a[j][m-1]+(b[m-1]?-a[j+m][m-1]:a[j+m][m-1]);
			s2-=a[j][m-1]+(b[m-1]?-a[j+m][m-1]:a[j+m][m-1]);
			sum+=max(s1,s2);
			//if(i==2)cout<<s1<<" "<<s2<<endl;
		}
		for(int j=0;j<m-1;j++)sum+=(b[j]?-1:1)*(a[m-1][j]+(b[m-1]?-a[m-1][j+m]:a[m-1][j+m])); sum+=b[m-1]?-a[m-1][m-1]:a[m-1][m-1];
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
}