#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
const int N=100005;
int n,c,d,t[N],p[N],nex[N];
int main(){
	scanf("%d%d%d",&n,&c,&d);
	rep(i,1,n){
		scanf("%d",&t[i]);
		char ch;
		cin>>ch;
		p[i]=ch=='P';
	}
	scanf("%d",&t[n+1]);
	int last[2]={n+1,n+1};
	per(i,n,1){
		nex[i]=last[p[i]^1];
		last[p[i]]=i;
	}
	LL ans=1LL*d*n;
	LL old=0;
	for(int i=n,j;i>=1;i=j){
		j=i;
		while(j>=1&&p[i]==p[j])--j;
		LL cur=0,now=INFLL;
		per(k,i,j+1){
			cur+=1LL*(t[nex[k]]-t[k])*c;
			ans=min(ans,1LL*(k-1)*d+old+cur);
			
			now=min(now,cur+1LL*(t[k]-t[j+1])*c+1LL*(k-j-1)*d);
		}
		old+=now;
	}
	printf("%lld\n",ans);
	return 0;
}