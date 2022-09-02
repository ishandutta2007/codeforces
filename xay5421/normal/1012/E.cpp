// author: xay5421
// created: Mon Nov 15 22:52:52 2021
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
struct ufs{
	int n;
	vector<int>fa;
	ufs(int n):n(n){
		fa.assign(n,0);
		rep(i,0,n-1)fa[i]=i;
	}
	int fd(int k1){
		return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);
	}
	int chk(int k1,int k2){
		return fd(k1)==fd(k2);
	}
	int mer(int k1,int k2){
		k1=fd(k1),k2=fd(k2);
		if(k1==k2)return 0;
		fa[k1]=k2;
		return 1;
	}
};
const int N=200005;
int n,maxx,a[N],id[N],pre[N],nex[N],seq[N];
bool vis[N];
int main(){
	scanf("%d%d",&n,&maxx);
	rep(i,1,n)scanf("%d",&a[i]),id[i]=i;
	sort(id+1,id+1+n,[&](int x,int y){return a[x]<a[y];});
	int m=0;
	rep(i,1,n){
		if(a[i]!=a[id[i]]){
			seq[++m]=i;
			id[m]=i;
		}else{
			pre[i]=nex[i]=i;
		}
	}
	ufs o(n+1);
	sort(id+1,id+1+m,[&](int x,int y){return a[x]<a[y];});
	rep(i,1,m){
		nex[seq[i]]=id[i],pre[id[i]]=seq[i];
		o.mer(seq[i],id[i]);
	}
	for(int i=1,j;i<=m;i=j){
		j=i+1;
		while(j<=m&&a[id[i]]==a[id[j]])++j;
		rep(k,i+1,j-1){
			if(o.fd(id[k])!=o.fd(id[i])){
				int k1=id[i],k2=id[k],k3=pre[k1],k4=pre[k2];
				pre[k1]=k4,nex[k4]=k1,pre[k2]=k3,nex[k3]=k2;
				o.mer(k1,k2);
			}
		}
	}
	vector<vector<int> >cycs;
	int minx=0;
	rep(i,1,n)if(!vis[i]&&nex[i]!=i){
		vector<int>cyc;
		int x=i;
		while(!vis[x]){
			vis[x]=1;
			cyc.pb(x);
			x=pre[x];
		}
		cycs.pb(cyc);
		minx+=SZ(cyc);
	}
	if(minx>maxx){
		puts("-1"),exit(0);
	}
	/*if(maxx==198000){
		printf("minx=%d maxx=%d SZ(cycs)=%d\n",minx,maxx,SZ(cycs));
	}*/
	if(SZ(cycs)<=2||maxx-minx<=2){
		printf("%d\n",SZ(cycs));
		for(auto&cyc:cycs){
			printf("%d\n",SZ(cyc));
			for(auto x:cyc)printf("%d ",x);
			puts("");
		}
		return 0;
	}else if(minx+SZ(cycs)<=maxx){
		printf("2\n");
		printf("%d\n",SZ(cycs));
		per(i,SZ(cycs)-1,0){
			printf("%d ",cycs[i][0]);
		}
		puts("");
		printf("%d\n",minx);
		rep(i,0,SZ(cycs)-1){
			printf("%d ",cycs[(i+SZ(cycs)-1)%SZ(cycs)][0]);
			rep(j,1,SZ(cycs[i])-1)printf("%d ",cycs[i][j]);
		}
		puts("");
	}else{
		int k=maxx-minx;
		printf("%d\n",2+SZ(cycs)-k);
		int sz=0;
		printf("%d\n",k);
		per(i,k-1,0){
			printf("%d ",cycs[i][0]);
			sz+=SZ(cycs[i]);
		}
		puts("");
		printf("%d\n",sz);
		rep(i,0,k-1){
			printf("%d ",cycs[(i+k-1)%k][0]);
			rep(j,1,SZ(cycs[i])-1)printf("%d ",cycs[i][j]);
		}
		puts("");
		rep(i,k,SZ(cycs)-1){
			printf("%d\n",SZ(cycs[i]));
			for(auto&x:cycs[i])printf("%d ",x);
			puts("");
		}
	}
	return 0;
}