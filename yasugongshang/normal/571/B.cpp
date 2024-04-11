#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef int LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
    int x = 0; char ch = gc(); bool positive = 1;
    for (; !isdigit(ch); ch = gc())    if (ch == '-')    positive = 0;
    for (; isdigit(ch); ch = gc())    x = x * 10 + ch - '0';
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
const int N=300005;
int ans;
int n,k,a[N],b[N],dp[5005][5005];
int main(){
	//freopen("rice1.in","r",stdin); freopen("rice1.out","w",stdout);
    n=read(); k=read();
    for(int i=1;i<=n;i++)a[i]=read(); sort(&a[1],&a[n+1]);
    int n1=n%k,n2=k-n%k,l1=n/k+1,l2=n/k;
    for(int i=0;i<=n1;i++)for(int j=0;j<=n2;j++)dp[i][j]=4e18; dp[0][0]=0;
    for(int i=0;i<=n1;i++)for(int j=0;j<=n2;j++){
        if(i<n1)dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a[(i+1)*l1+j*l2]-a[i*l1+j*l2+1]);
        if(j<n2)dp[i][j+1]=min(dp[i][j+1],dp[i][j]+a[i*l1+(j+1)*l2]-a[i*l1+j*l2+1]);
    }
    cout<<dp[n1][n2]<<endl;
}