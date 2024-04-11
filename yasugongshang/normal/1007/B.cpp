#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define int long long
#define gc getchar
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
const int N=100005;
int t1,t2,t3;
int q1[N],q2[N],tong[10],f[N],g[N];
bool c(int a,int b,int c){
	return (a&1)&&(b&2)&&(c&4);
}
bool check(int x,int y,int z){
	return c(x,y,z)||c(x,z,y)||c(y,x,z)||c(y,z,x)||c(z,x,y)||c(z,y,x);
}
signed main(){
	int T=read();
	for(int i=1;i<=100000;i++){
		g[i]=(ll)i*(i+1)/2;
		f[i]=f[i-1]+g[i];
		//if(i<=5)cout<<f[i]<<" "<<g[i]<<endl;
	}
	while(T--){
		int a=read(),b=read(),c=read(); ll ans=0;
		t1=t2=t3=0; memset(tong,0,sizeof(tong));
		for(int i=1;i*i<=a;i++)if(a%i==0){
			q1[++t1]=i; if(i*i!=a)q1[++t1]=a/i;
		}
		for(int i=1;i*i<=b;i++)if(b%i==0){
			q2[++t2]=i; if(i*i!=b)q2[++t2]=b/i;
		}
		for(int i=1;i*i<=c;i++)if(c%i==0){
			t3++; if(i*i!=c)t3++;
		}
		for(int i=1;i<=t1;i++){
			int s=1;
			if(b%q1[i]==0)s|=2;
			if(c%q1[i]==0)s|=4;
			tong[s]++;
		}
		for(int i=1;i<=t2;i++)if(a%q2[i]){
			int s=2;
			if(c%q2[i]==0)s|=4;
			tong[s]++;
		}
		//cout<<t1<<" "<<t2<<" "<<t3<<" "<<tong[7]<<endl;
		tong[1]=t1-tong[3]-tong[5]-tong[7];
		tong[2]=t2-tong[3]-tong[6]-tong[7];
		tong[4]=t3-tong[5]-tong[6]-tong[7];
		//for(int i=1;i<8;i++)cout<<tong[i]<<" "<<i<<endl;
		for(int i=1;i<8;i++){
			for(int j=i;j<8;j++){
				for(int k=j;k<8;k++)if(check(i,j,k)){
					if(i==j&&i==k)ans+=f[tong[i]];
					else if(i==j)ans+=g[tong[i]]*tong[k];
					else if(i==k)ans+=g[tong[i]]*tong[j];
					else if(j==k)ans+=g[tong[j]]*tong[i];
					else
					ans+=(ll)tong[i]*tong[j]*tong[k];
					//cout<<i<<" "<<j<<" "<<k<<" "<<ans<<endl;
				}
			}
		}
		writeln(ans);
	}
}
/*
1
1 2 2
*/