#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
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
inline void wri(ll a){write(a); putchar(' ');}
inline void writeln(ll a){write(a); puts("");}
const int N=100005,K=18;
int n,a[N],quan,g[N][K],f[N][K];
struct data{
	int tf[N<<2],tg[N<<2];
	void build(int l,int r,int nod){
		if(l==r){
			tf[nod]=f[l][quan]-l; tg[nod]=g[l][quan]+l; return;
		}
		int mid=(l+r)>>1;
		build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
		tf[nod]=max(tf[nod<<1],tf[nod<<1|1]); tg[nod]=max(tg[nod<<1],tg[nod<<1|1]);
	}
	int askf(int l,int r,int i,int j,int nod){
		if(l==i&&r==j)return tf[nod];
		int mid=(l+r)>>1;
		if(j<=mid)return askf(l,mid,i,j,nod<<1);
		else if(i>mid)return askf(mid+1,r,i,j,nod<<1|1);
		else return max(askf(l,mid,i,mid,nod<<1),askf(mid+1,r,mid+1,j,nod<<1|1));
	}
	int askg(int l,int r,int i,int j,int nod){
		if(l==i&&r==j)return tg[nod];
		int mid=(l+r)>>1;
		if(j<=mid)return askg(l,mid,i,j,nod<<1);
		else if(i>mid)return askg(mid+1,r,i,j,nod<<1|1);
		else return max(askg(l,mid,i,mid,nod<<1),askg(mid+1,r,mid+1,j,nod<<1|1));
	}
}T[K];
signed main(){
	n=read();
	if(n==1){
		puts("0"); return 0;
	}
	for(int i=0;i<n;i++)a[i]=read();
	for(int i=0;i<n;i++){
		if(a[i]*2+1>=n){
			f[i][0]=g[i][0]=n-1;
		}else{
			f[i][0]=g[i][0]=a[i];
		}
	}
	for(int i=1;i<K;i++){
		quan=i-1; T[i-1].build(0,n-1,1);// f f[j]-j
		for(int j=0;j<n;j++){
			int l=(j+n-f[j][i-1])%n,r=(j+g[j][i-1])%n;
			if(l>j){
				f[j][i]=max(T[i-1].askf(0,n-1,0,j,1)+j,T[i-1].askf(0,n-1,l,n-1,1)+n+j);
				g[j][i]=max(T[i-1].askg(0,n-1,0,j,1)-j,T[i-1].askg(0,n-1,l,n-1,1)-n-j);
			}else{
				f[j][i]=T[i-1].askf(0,n-1,l,j,1)+j;
				g[j][i]=T[i-1].askg(0,n-1,l,j,1)-j;
			}
			if(r<j){
				g[j][i]=max(g[j][i],max(T[i-1].askg(0,n-1,j,n-1,1)-j,T[i-1].askg(0,n-1,0,r,1)+n-j));
				f[j][i]=max(f[j][i],max(T[i-1].askf(0,n-1,j,n-1,1)+j,T[i-1].askf(0,n-1,0,r,1)-n+j));
			}else{
				g[j][i]=max(g[j][i],T[i-1].askg(0,n-1,j,r,1)-j);
				f[j][i]=max(f[j][i],T[i-1].askf(0,n-1,j,r,1)+j);
			}
			if(f[j][i]+g[j][i]+1>=n){
				f[j][i]=g[j][i]=n-1;
			}
			//if(j==5)cout<<f[j][i]<<" "<<g[j][i]<<" "<<j<<" "<<i<<" "<<l<<" "<<r<<" "<<T[0].askf(0,n-1,1,2,1)<<endl;
		}
	}
	quan=K-1; T[K-1].build(0,n-1,1);
	for(int j=0;j<n;j++){
		int ff=0,gg=0,fff,ggg,ans=0;
		for(int i=K-1;i>=0;i--)if(f[j][i]+g[j][i]+1<n){
			int l=(j+n-ff)%n,r=(j+gg)%n;
			if(l>j){
				fff=max(T[i].askf(0,n-1,0,j,1)+j,T[i].askf(0,n-1,l,n-1,1)+n+j);
				ggg=max(T[i].askg(0,n-1,0,j,1)-j,T[i].askg(0,n-1,l,n-1,1)-n-j);
			}else{
				fff=T[i].askf(0,n-1,l,j,1)+j;
				ggg=T[i].askg(0,n-1,l,j,1)-j;
			}
			if(r<j){
				ggg=max(ggg,max(T[i].askg(0,n-1,j,n-1,1)-j,T[i].askg(0,n-1,0,r,1)+n-j));
				fff=max(fff,max(T[i].askf(0,n-1,j,n-1,1)+j,T[i].askf(0,n-1,0,r,1)-n+j));
			}else{
				ggg=max(ggg,T[i].askg(0,n-1,j,r,1)-j);
				fff=max(fff,T[i].askf(0,n-1,j,r,1)+j);
			}
			//if(j==2)cout<<f[j][i]<<" "<<g[j][i]<<" "<<fff<<" "<<ggg<<endl;
			if(fff+ggg+1<n){
				ff=fff; gg=ggg; ans+=1<<i;
			}
		}
		wri(ans+1);
	}
	
}
/*
11
1 1 2 1 1 3 1 1 2 1 1

*/