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
#define int long long
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
const int N=50005,size=2;
struct matrix{
    int a[2][2];
}tree[N<<2],ans;
int n,k,s[N],mod,m;
matrix operator *(matrix x,matrix y){
    matrix tmp;
    for(int i=0;i<size;i++)
    	for(int j=0;j<size;j++){
			tmp.a[i][j]=0;
      		for(int k=0;k<size;k++){
          		tmp.a[i][j]=(tmp.a[i][j]+(long long)x.a[i][k]*y.a[k][j])%mod;
      		}
		}
    return tmp;
}
inline matrix mm(int a,int b){
	matrix tmp; tmp.a[1][0]=1; tmp.a[1][1]=b; tmp.a[0][1]=a; tmp.a[0][0]=0; return tmp;
}
void build(int l,int r,int nod){
	if(l==r){
		tree[nod]=mm(s[(l+n-2)%n],s[(l+n-1)%n]); return;
	}
	int mid=(l+r)>>1;
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
	tree[nod]=tree[nod<<1]*tree[nod<<1|1];
}
matrix ask(int l,int r,int i,int j,int nod){
	if(l==i&&r==j)return tree[nod];
	int mid=(l+r)>>1;
	if(j<=mid)return ask(l,mid,i,j,nod<<1); else if(i>mid)return ask(mid+1,r,i,j,nod<<1|1);
	else return ask(l,mid,i,mid,nod<<1)*ask(mid+1,r,mid+1,j,nod<<1|1);
}
map<int,int> M;
matrix ksm(matrix ans,matrix a,int k){
	for(;k;k>>=1){
		if(k&1)ans=ans*a;
		a=a*a;
	}
	return ans;
}
signed main(){
	k=read(); mod=read(); if(k==0){
		puts("0"); return 0;
	}
	n=read();
	for(int i=0;i<n;i++)s[i]=read();
 	m=read();
 	for(int i=1;i<=m;i++){
 		int pos=read();
 		M[pos]=read();
	 }
	 if(!M.count(k))M[k]=s[k%n]; build(0,n-1,1);
	ans.a[0][0]=0; ans.a[0][1]=1; int dq=1;
	while(dq<k){
		if(M.count(dq-1)||M.count(dq)){
			//cout<<ans.a[0][0]<<" "<<ans.a[0][1]<<" afsg "<<mm(M.count(dq)?M[dq]:s[dq%n],M.count(dq+1)?M[dq+1]:s[(dq+1)%n]).a[1][1]<<endl;
			//for(int i=0;i<2;i++)for(int j=0;j<2;j++)cout<<mm(M.count(dq)?M[dq]:s[dq%n],M.count(dq+1)?M[dq+1]:s[(dq+1)%n]).a[i][j]<<endl;
			ans=ans*mm(M.count(dq-1)?M[dq-1]:s[(dq+n-1)%n],M.count(dq)?M[dq]:s[dq%n]); dq++;
		}else{
			int t=M.lower_bound(dq)->first; dq++;
			if(t/n==dq/n){
				ans=ans*ask(0,n-1,dq%n,t%n,1);
			}else{
				ans=ans*ask(0,n-1,dq%n,n-1,1); //cout<<ask(0,n-1,dq%n,n-1,1).a[0][1]<<" zhu "<<ans.a[0][1]<<endl;
				ans=ksm(ans,tree[1],(t-dq/n*n-n)/n);
				ans=ans*ask(0,n-1,0,t%n,1);
			}
			dq=t;
		}
		//cout<<dq<<" "<<ans.a[0][0]<<" "<<ans.a[0][1]<<endl;
	}
	cout<<ans.a[0][1]%mod<<endl;
}
/*
  1 2 1 1 4 1 3 2
0 1 1 3 5 8 37 37 148
0 213845
4
5 4 123 4
*/