#include<map>
#include<cstdio>
#include<algorithm>
#define fi first
#define se second

const int N=100005;
typedef std::pair<int,int> pii;

int n,q[N],pre[N];
std::map<pii,pii>f;
pii ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int v,c,l,r;scanf("%d%d%d%d",&v,&c,&l,&r);
		pii tmp=std::make_pair(l,r+c);
		if(f.count(tmp)||l==0){
			pii now=std::make_pair(l+c,r);
			if(f[tmp].fi+v>f[now].fi)
				f[now].fi=f[tmp].fi+v,f[now].se=i,pre[i]=f[tmp].se;
			if(f[now].fi>f[ans].fi&&r==0)ans=now;
		}
	}
	int u=f[ans].se;
	while(u){
		q[++*q]=u;
		u=pre[u];
	}
	printf("%d\n",*q);
	for(int i=*q;i>=1;--i)printf("%d ",q[i]);
	return 0;
}