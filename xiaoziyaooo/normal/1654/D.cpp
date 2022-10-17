#include<bits/stdc++.h>
using namespace std;
const int maxn=500005,mod=998244353;
int n,T,ans,ps,val;
int p[maxn],mn[maxn],c[maxn],inv[maxn],xx[maxn],yy[maxn],aa[maxn],bb[maxn],tot[maxn],mx[maxn];
vector<int>v[maxn],V;
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}
void sieve(int n){
	c[1]=inv[1]=1;
	for(int i=2;i<=n;i++){
		inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
		if(c[i]==0)
			p[++ps]=i,mn[i]=i;
		for(int j=1;j<=ps&&i*p[j]<=n;j++){
			mn[i*p[j]]=p[j],c[i*p[j]]=1;
			if(i%p[j]==0)
				break;
		}
	}
}
void get(int x,int v){
//	printf("get %d %d\n",x,v);
	while(x>1){
		int p=mn[x];
		while(x%p==0)
			x/=p,tot[p]+=v;
		V.push_back(p);
	}
}
void dfs(int x,int last){
	for(int i=0;i<v[x].size();i++){
		int k=v[x][i],y=xx[k]+yy[k]-x,a=aa[k],b=bb[k];
		if(y==last)
			continue;
		if(xx[k]==x)//a:b
			get(a,1),get(b,-1);
		else get(b,1),get(a,-1);//b:a
		for(int j=0;j<V.size();j++)
			mx[V[j]]=max(mx[V[j]],tot[V[j]]);
		V.clear();
//		printf("%d->%d\n",x,y);
		dfs(y,x);
		if(xx[k]==x)//a:b
			get(a,-1),get(b,1);
		else get(b,-1),get(a,1);//b:a
		V.clear();
	}
}
void use(int x,int v){
	if(v==-1)
		val=1ll*val*x%mod;
	else val=1ll*val*inv[x]%mod;
}
void calc(int x,int last){
//	printf("x=%d val=%d\n",x,val);
	ans=(ans+val)%mod;
	for(int i=0;i<v[x].size();i++){
		int k=v[x][i],y=xx[k]+yy[k]-x,a=aa[k],b=bb[k];
		if(y==last)
			continue;
		if(xx[k]==x)//a:b
			use(a,1),use(b,-1);
		else use(b,1),use(a,-1);//b:a
		calc(y,x);
		if(xx[k]==x)//a:b
			use(a,-1),use(b,1);
		else use(b,-1),use(a,1);//b:a
	}
}
int main(){
	scanf("%d",&T);
	sieve(300000);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<n;i++)
			scanf("%d%d%d%d",&xx[i],&yy[i],&aa[i],&bb[i]),v[xx[i]].push_back(i),v[yy[i]].push_back(i);
		dfs(1,0),val=1;
		for(int i=1;i<=ps&&p[i]<=n;i++){
//			printf("i=%d p=%d mx=%d\n",i,p[i],mx[p[i]]);
			val=1ll*val*ksm(p[i],mx[p[i]])%mod,tot[p[i]]=mx[p[i]]=0;
		}
//		printf("val=%d\n",val);
		ans=0,calc(1,0);
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			v[i].clear();
	}
	return 0;
}