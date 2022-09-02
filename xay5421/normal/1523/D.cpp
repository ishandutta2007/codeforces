// author: xay5421
// created: Sun May 30 23:24:00 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int N=200005;
int n,m,p,a[N][65],st[65],top,f[(1<<15)+5],res[N];
pair<int,int>ans={0,0};
void sol(int cur){
	top=0;
	rep(i,0,m-1)if(a[cur][i])st[++top]=i;
	rep(i,0,(1<<top)-1)f[i]=0;
	rep(i,1,n){
		int num=0;
		rep(j,1,top)if(a[i][st[j]])num|=1<<(j-1);
		++f[num];
	}
	for(int i=1;i<(1<<top);i<<=1)for(int j=0;j<(1<<top);j+=i<<1)for(int k=0;k<i;++k){
		f[j+k]+=f[i+j+k];
	}
	rep(i,0,(1<<top)-1)if(f[i]>=(n+1)/2){
		if(__builtin_popcount(i)>__builtin_popcount(ans.first))ans=make_pair(i,cur);
	}
}
void out(int cur,int s){
	top=0;
	rep(i,0,m-1)if(a[cur][i])st[++top]=i;
	rep(i,0,top-1)if(s>>i&1)res[st[i+1]]=1;
	rep(i,0,m-1)printf("%d",res[i]);
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	rep(i,1,n){
		rep(j,0,m-1){
			char c;
			while(!isdigit(c=getchar()));
			a[i][j]=c&1;
		}
	}
	rep(_,1,20){
		int x=rng()%n+1;
		sol(x);
	}
	out(ans.second,ans.first);
	return 0;
}