#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<ctime>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
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
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=101,mod=1000000007;
int n,x,tong[N],sum,tmp[N][N],a[N][N],dp[N][N],ans[N][N];
void mul(int a[N][N],int b[N][N],int id){
	memset(tmp,0,sizeof(tmp));
	for(int i=0;i<=id;i++){
		for(int j=0;j<=100;j++){
			for(int k=0;k<=100;k++){
				tmp[i][j]=(tmp[i][j]+(ll)a[i][k]*b[k][j])%mod;
			}
		}
	}
	memcpy(a,tmp,sizeof(tmp));
}
void ksm(int ans[N][N],int k){
	for(;k;k>>=1){
		if(k&1)mul(ans,a,0);
		mul(a,a,100);
	}
}
int main(){
	n=read(); x=read();
	for(int i=1;i<=n;i++)tong[read()]++;
	sum=dp[0][0]=1;
	if(x==0){puts("1"); return 0;}
	for(int i=1;i<100;i++){
		for(int j=1;j<=i;j++)dp[0][i]=(dp[0][i]+(ll)dp[0][i-j]*tong[j])%mod;
		sum=(sum+dp[0][i])%mod;
		if(x==i){
			writeln(sum); return 0;
		}
	}
	dp[0][100]=sum;
	for(int i=0;i<100;i++){
		if(i)a[i][i-1]=1;
		a[i][99]=tong[100-i];
		a[i][100]=tong[100-i];
	}
	a[100][100]=1;
	ksm(dp,x-99);
	cout<<dp[0][100]<<endl;
}