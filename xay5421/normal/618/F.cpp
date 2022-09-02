#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int N=1000005;
int n,go[N];
LL a[N],b[N];
pair<int,int>mem[N];
void output(LL*a,int l,int r){
	printf("%d\n",r-l);
	rep(i,l+1,r){
		printf("%d ",i);
	}
	puts("");
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&a[i]),a[i]+=a[i-1];
	rep(i,1,n)scanf("%lld",&b[i]),b[i]+=b[i-1];
	bool flg=0;
	if(a[n]>b[n]){
		swap(a,b);
		flg=1;
	}
	fill(mem,mem+n,make_pair(-1,-1));
	tuple<int,int,int,int>ans={-1,-1,-1,-1};
	rep(i,0,n){
		go[i]=i==0?0:go[i-1];
		while(b[go[i]]<a[i]){
			++go[i];
		}
		int delta=b[go[i]]-a[i];
		int u,v;
		tie(u,v)=mem[delta];
		if(u!=-1){
			ans={u,i,v,go[i]};
			break;
		}
		mem[delta]={i,go[i]};
	}
	int l1,r1,l2,r2;
	tie(l1,r1,l2,r2)=ans;
	if(flg){
		output(b,l2,r2);
		output(a,l1,r1);
	}else{
		output(a,l1,r1);
		output(b,l2,r2);
	}
	return 0;
}