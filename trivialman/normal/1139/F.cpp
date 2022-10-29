#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define PB push_back
const int N = 1e5+5;
 
struct dat1{
	int p,s,b;
}a[N];
struct dat2{
	int inc,pref,ans;
}b[N];
vector<array<int,3>> in[N*3], out[N*3], ask[N*3];
int n,m,x[N*2],y[N*2],z[N*3];
unordered_map<int,int> mp1,mp2,mp3;
struct BIT{
	int a[N<<1];
	void add(int x,int val){for(;x<=n+m;x+=x&-x)a[x]+=val;}
	int get(int x){int res=0;for(;x;x-=x&-x)res+=a[x];return res;}
}tr1, tr2;
 
void dscrt(int *x, unordered_map<int,int> &mp, int k){
	sort(x+1,x+k+1);
	int cnt = 0;
	x[0] = -1.5e9;
	rep(i,1,k){
		if(x[i]!=x[i-1]) ++cnt;
		mp[x[i]] = cnt;
	}
}
 
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i].p);
	rep(i,1,n)scanf("%d",&a[i].s);
	rep(i,1,n)scanf("%d",&a[i].b);
	rep(i,1,m)scanf("%d",&b[i].inc);
	rep(i,1,m)scanf("%d",&b[i].pref);
	
	rep(i,1,n){
		int p = a[i].p, s = a[i].s, b = a[i].b;
		x[i]=b+p, y[i]=b+1-p, z[i*2-1]=p, z[i*2]=s+1;
	}
	rep(i,1,m){
		int p=b[i].pref, I=b[i].inc;
		x[n+i]=p+I, y[n+i]=p-I, z[n+n+i]=I;
	}
	dscrt(x,mp1,n+m), dscrt(y,mp2,n+m), dscrt(z,mp3,n+n+m);
	rep(i,1,n){
		int p = a[i].p, s = a[i].s, b = a[i].b;
		in[mp3[p]].PB({0,mp1[b+p],mp2[b+1-p]});
		out[mp3[s+1]].PB({0,mp1[b+p],mp2[b+1-p]});
	}
	rep(i,1,m){
		int p=b[i].pref, I=b[i].inc;
		ask[mp3[I]].PB({i,mp1[p+I],mp2[p-I]});
	}
	
	rep(i,1,mp3.size()){
		for(auto u:in[i]) tr1.add(u[1],1), tr2.add(u[2],1);
		for(auto u:out[i]) tr1.add(u[1],-1), tr2.add(u[2],-1);
		for(auto u:ask[i]) b[u[0]].ans = tr1.get(u[1]) - tr2.get(u[2]);
	}
	rep(i,1,m) printf("%d ",b[i].ans);
	return 0;
}