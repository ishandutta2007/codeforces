#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
#define ld double
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
const int N=85;
int n,tot,L[N],r[N],q[N<<1];
ld dp[N][N],ans[N][N],sum[N],len[N];
signed main(){
	n=read();
	for(int i=1;i<=n;i++){L[i]=read(); r[i]=read(); q[++tot]=L[i]; q[++tot]=r[i];}
	sort(&q[1],&q[tot+1]);
	tot=unique(&q[1],&q[tot+1])-q-1;
	for(int i=1;i<=n;i++){
		len[i]=r[i]-L[i];
		L[i]=lower_bound(&q[1],&q[tot+1],L[i])-q; r[i]=lower_bound(&q[1],&q[tot+1],r[i])-q; //cout<<L[i]<<" "<<r[i]<<endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=L[i];j<r[i];j++){
			memset(dp,0,sizeof(dp)); dp[0][0]=1;
			for(int k=1;k<=n;k++)if(i!=k){
				ld t1=(L[k]<=j&&r[k]>j)?(q[j+1]-q[j])/len[k]:0,t2=(L[k]<j)?(min(q[j]-q[L[k]],(int)len[k])/len[k]):0,t3=(r[k]>j)?min(q[r[k]]-q[j+1],(int)len[k])/len[k]:0;
				if(L[k]>j)continue;
				for(register int l=k;l>=0;l--){
					for(register int o=k-l;o>=0;o--)if(dp[l][o]>0){
						dp[l+1][o]+=dp[l][o]*t1;
						dp[l][o+1]+=dp[l][o]*t2;
						dp[l][o]=dp[l][o]*t3; 
					}
				}
			}
			for(int l=0;l<=n;l++)sum[l]=0;
			for(int l=0;l<=n;l++){
				for(int o=0;l+o<=n;o++)if(dp[l][o]>0){
					//cout<<dp[l][o]<<" "<<i<<" "<<l<<" "<<o<<endl;
					sum[o+1]+=dp[l][o]/(l+1); sum[o+l+2]-=dp[l][o]/(l+1);
				}
			}
			for(int l=1;l<=n;l++){sum[l]+=sum[l-1]; ans[i][l]+=sum[l]*(q[j+1]-q[j])/len[i];}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)printf("%.6lf ",(double)ans[i][j]); puts("");
	}
}