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
const int N=5050000,NN=200000;
bitset<N> heshu;
int n,Q,pos[9],ans[17][NN],a[N],pri[N],q[N],ycl[N],f[N];
vector<int> v[N];
int main(){
	n=read(); Q=read();
	for(int i=1;i<N;i++)ycl[i]=i;
	int t=sqrt(N);
	for(int i=2;i<N;i++)if(!heshu[i]){
		for(int j=i+i;j<N;j+=i)heshu[j]=i;
		for(int j=i;j<N;j+=i)pri[j]=i; 
		int ttt=i*i;
		if(i<=t)for(int j=ttt;j<N;j+=ttt)while(ycl[j]%ttt==0)ycl[j]/=ttt;
	}
	for(int i=2;i<N;i++)f[i]=f[i/pri[i]]+1;
	for(int i=1;i<=n;i++){
		int t=ycl[read()];
		a[i]=f[t];
		v[t].push_back(i);
	}
	for(int i=1;i<N;i++){
		int tot=0;
		for(int j=i;j<N;j+=i){
			for(auto k:v[j])q[++tot]=k;
		}
		sort(&q[1],&q[tot+1]);
		//if(tot)cout<<f[i]<<" "<<i<<" "<<tot<<endl;
		for(int k=f[i];k<=8;k++)pos[k]=0;
		for(int j=1;j<=tot;j++){
			for(int k=f[i];k<=8;k++)if(pos[k]){
				//if(k+a[q[j]]-2*f[i]==1)cout<<q[j]<<" zyy "<<pos[k]<<endl;
				ans[k+a[q[j]]-2*f[i]][q[j]]=max(ans[k+a[q[j]]-2*f[i]][q[j]],pos[k]);
			}
			pos[a[q[j]]]=q[j];
		}
	}
	//cout<<ans[1][3]<<endl;
	
	for(int i=0;i<=16;i++){
		for(int j=1;j<=n;j++)ans[i][j]=max(ans[i][j-1],ans[i][j]);
	}
	while(Q--){
		int l=read(),r=read();
		for(int j=0;j<=16;j++)if(ans[j][r]>=l){
			writeln(j); break;
		}
	}
}