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
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
inline int rnd(int x){
	return rand()%x;
}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=2005;
int n,k,a,b,c,tot,que[N/3],ycl[N][N];
char miu[N];
ll ans;
bitset<N> vis,heshu;
inline int qiu(int i,int j){
	if(j==0)return i;
	if(ycl[i][j])return ycl[i][j];
	return qiu(j,i%j);
}
int main(){
	a=read(); b=read(); c=read(); 
	if(a>b)swap(a,b); if(a>c)swap(a,c);
	if(b>c)swap(b,c); n=c;
	miu[1]=1;
	for(int i=2;i<=n;i++){
		if(!heshu[i]){
			que[++tot]=i; miu[i]=-1;
		}
		for(int j=1;j<=tot&&que[j]*i<=n;j++){
			int k=que[j]*i;
			heshu[k]=1;
			if(i%que[j]==0){miu[k]=0; break;}
			miu[k]=-miu[i];
		}
	}
	heshu[1]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ycl[i][j]=qiu(i,j);
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			int sum1=0,sum2=0;
			for(int k=j;k<=b;k+=j)if(ycl[i][k]==1)sum1+=b/k;
			for(int k=j;k<=c;k+=j)if(ycl[i][k]==1)sum2+=c/k;
			//cout<<j<<" "<<(int)miu[j]<<" "<<sum1<<" "<<sum2<<endl;
			ans=(ans+miu[j]*sum1*sum2*(a/i));
		}
	}
	unsigned jb=ans;
	cout<<jb%(1<<30)<<endl;
}