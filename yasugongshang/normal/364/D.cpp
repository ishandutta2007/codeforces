#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
#define int long long
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define getchar gc
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=1000005,mod=1e7+7;
int a[N],q[100000],n,tt[100000],ans;
struct has_table{
	bool has[mod];
	int a[mod],v[mod];
	int b[mod],size;
	inline void insert(int x,int de){
		for(int i=x%mod;;i=i+1==mod?0:i+1){
			if(!has[i]||a[i]==x){
				v[++size]=i;
				has[i]=1; b[i]+=de; a[i]=x; return;
			}
		}
	}
	inline int find(int x){
		for(int i=x%mod;;i=i+1==mod?0:i+1){
			if(!has[i]||a[i]==x){
				return b[i];
			}
		}
	}
	void clear(){
		for(int i=1;i<=size;i++)has[v[i]]=a[v[i]]=b[v[i]]=0;
		size=0;
	}
}has;
int calc(int pos){
	int x=a[pos],tot=0; has.clear();
	for(int i=1;i*i<=x;i++)if(x%i==0){
		q[++tot]=i; if(i*i!=x)q[++tot]=x/i;
	}
	sort(&q[1],&q[tot+1]);
	for(int i=1;i<=n;i++){
		int t=__gcd(x,a[i]);
		has.insert(t,1);
	}
	for(int i=tot;i;i--){
		tt[i]=has.find(q[i]); int sum=0; //cout<<pos<<" "<<tt[i]<<" "<<q[i]<<" "<<tot<<endl;
		for(int j=i;j<=tot;j++)if(q[j]%q[i]==0){
			//if(q[i]==3)cout<<j<<" "<<q[j]<<endl;
			sum+=tt[j];
		}
		if(sum>=(n+1)/2)return q[i];
	}
}
signed main(){
	int seed=19260817;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(); //calc(6); return 0;
	for(int i=1;i<=9&&i<=n;i++)ans=max(ans,calc(seed=((seed*2+3)%n+1)));
	writeln(ans);
}