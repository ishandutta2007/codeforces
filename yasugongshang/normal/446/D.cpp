#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
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
const int N=505;
#define ld double
struct matrix{
	ld a[N][N];
	inline ld* operator [] (int x){
        return a[x];
    }
    void clear(){
    	memset(a,0,sizeof(a));
	}
}A,g,ans,b,tmp;
int n,m,k,a[N],B[N];
vector<int> v[N];
matrix inv(matrix a){
	b.clear();
	for(int i=1;i<=n;i++)b[i][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)if(a[j][i]){
			swap(a.a[i],a.a[j]); swap(b.a[i],b.a[j]); break;
		}
		if(fabs(a[i][i])<1e-12)while(1);
		for(int j=1;j<=n;j++)b[i][j]/=a[i][i];
		for(int j=n;j>=i;j--)a[i][j]/=a[i][i];
		for(int j=1;j<=n;j++)if(i!=j){
			ld t=a[j][i];
			for(int k=1;k<=n;k++)b[j][k]-=t*b[i][k];
			for(int k=1;k<=n;k++){ a[j][k]-=t*a[i][k];}
		}
	}
	//for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<a[i][j]<<" "; puts("");}
	
	return b;
}
int tot;
matrix operator *(matrix a,matrix b){
	tmp.clear(); 
	for(int i=1;i<=tot;i++){
		for(int j=1;j<=tot;j++){
			for(int k=1;k<=tot;k++){
				tmp[i][j]=tmp[i][j]+a[i][k]*b[k][j];
				//cout<<tmp[i][j]<<" "<<i<<" "<<j<<endl;
			}
		}
	}
	return tmp;
}
matrix ksm(matrix ans,matrix a,int k){
	for(;k;k>>=1){
		if(k&1)ans=ans*a;
		a=a*a;
	}
	return ans;
}
int q[N];
int main(){
	n=read(); m=read(); k=read();
	for(int i=1;i<=n;i++){a[i]=read(); if(a[i])q[++tot]=i;}
	for(int i=1;i<=m;i++){
		int s=read(),t=read();
		v[s].push_back(t); v[t].push_back(s);
	}
	for(int i=1;i<=n;i++){
		A[i][i]=1;
		if(a[i]==0)for(auto j:v[i]){
			A[i][j]+=(ld)-1/v[i].size();
		}
	}
	matrix x=inv(A);
	//for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cout<<x[i][j]<<" "<<i<<" "<<j<<endl;
	for(int i=1;i<=tot;i++)for(int j=1;j<=tot;j++){
		for(auto k:v[q[i]])g[i][j]+=x[k][q[j]]; g[i][j]/=v[q[i]].size();//cout<<g[i][j]<<" wzp "<<i<<" "<<j<<endl;
	}
	for(int i=1;i<=tot;i++)ans[1][i]=x[1][q[i]];
	//for(int i=1;i<=tot;i++)for(int j=1;j<=tot;j++)cout<<ans[i][j]<<" wzp "<<g[i][j]<<endl;
	matrix t=ksm(ans,g,k-2);
	printf("%.5lf\n",(double)t[1][tot]);
}
/*
if(!...)f[i]=0
else f[i]=1
f[i]=(sigma f[j])/rd[i]
*/