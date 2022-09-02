#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
int n,m,K;
int F(int opt,int x,int y,int rev){
	switch(opt){
		case 1: // AND
			return (x&y)^rev;
		case 2: // NAND
			return (x&y)^1^rev;
		case 3: // OR
			return (x|y)^rev;
		case 4: // NOR
			return (x|y)^1^rev;
	}
	assert(0);
}
struct node{
	int opt,x,y;
	void read(){
		string s,t;
		cin>>s>>t;
		if(s[0]=='a'){
			opt=1;
		}else if(s[1]=='a'){
			opt=2;
		}else if(s[0]=='o'){
			opt=3;
		}else{
			opt=4;
		}
		rep(i,0,SZ(t)-1)if(t[i]=='x'){
			x=i;
			rep(j,i+1,SZ(t)-1)if(t[j]=='x'){
				y=j;
				return;
			}
		}
		assert(0);
	}
}a[55],b[55];
int ss1[55],ss2[55];
int getss(const node&cur,int rev){
	LL vis=0;
	vis|=1LL<<a[cur.x].x;
	vis|=1LL<<a[cur.x].y;
	vis|=1LL<<a[cur.y].x;
	vis|=1LL<<a[cur.y].y;
	int can=0;
	for(LL mask=vis;;--mask&=vis){
		int lhs=F(a[cur.x].opt,mask>>a[cur.x].x&1,mask>>a[cur.x].y&1,rev);
		int rhs=F(a[cur.y].opt,mask>>a[cur.y].x&1,mask>>a[cur.y].y&1,rev);
		can|=1<<F(cur.opt,lhs,rhs,rev);
		if(!mask)break;
	}
	return can;
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	rep(i,0,m-1)a[i].read();
	rep(i,0,K-1){
		b[i].read();
		ss1[i]=getss(b[i],0);
		ss2[i]=getss(b[i],1);
	}
	int ans=0;
	{
		int tot=0,flg=0;
		rep(i,0,K-1){
			if(ss2[i]==1){
				++tot;
				flg|=ss1[i]==2;
			}
		}
		if(flg){
			ans=max(ans,tot);
		}
	}
	{
		int tot=0,flg=0;
		rep(i,0,K-1){
			if(ss1[i]==1){
				++tot;
				flg|=ss2[i]==2;
			}
		}
		if(flg){
			ans=max(ans,tot);
		}
	}
	if(!ans)puts("-1");
	else printf("%d\n",K-ans);
	return 0;
}