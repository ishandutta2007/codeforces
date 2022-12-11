#include <cstdio>
#include <utility>
#include <cstring>
#include <algorithm>
#define cs const
using namespace std;
typedef unsigned uint;
#define max_m 5000000
pair<uint,char> a[max_m+1];
pair<uint,uint> b[max_m+1];
uint c[max_m+1],par[max_m+1],siz[max_m+1],rk[max_m+1],f[max_m+1],arr[max_m+1];
int g[max_m+1];
uint sn[max_m+2];
bool s[max_m+1];
uint ton[256];
typedef cs uint* cpu;
struct node_stk{
	uint u,i;
};
node_stk dfs_stack[max_m+1];
typedef node_stk* pnode_stk;
int main(){
	uint m,n;
	scanf("%u",&m);
	memset(siz,0,sizeof(siz)),memset(ton,0,sizeof(ton)),memset(sn,0,sizeof(sn)),memset(s,0,sizeof(s));
	for(uint i=1; i<=m; ++i){
		scanf("%u %c",&a[i].first,&a[i].second);
		++ton[a[i].second],++sn[par[i]=a[i].first];
	}
	scanf("%u",&n);
	for(uint i=1,x; i<=n; ++i){
		scanf("%u",&x);
		arr[i]=x,siz[x]=1,s[x]=1;
	}
	for(uint i=m; i; --i)
		siz[par[i]]+=siz[i];
	uint now=1;
	for(uint i=1; i<256; ++i)
		now=ton[i]+=now;
	now=sn[0];
	for(uint i=1; i<m; ++i)
		now=sn[i]+=now;
	sn[m+1]=sn[m]=now;
	for(uint i=1; i<=m; ++i)
		b[--ton[a[i].second]]=make_pair(a[i].first,i);
	for(uint i=m; i; --i)
		c[--sn[b[i].first]]=b[i].second;
	rk[0]=0;
	for(uint i=0; i<m; ++i){
		uint l=sn[i],r=sn[i+1],now=rk[i]+s[i];
		for(uint j=l,v; j!=r; ++j){
			rk[v=c[j]]=now;
			now+=siz[v];
//			printf("(%d,%d)\n",i,v);
//			printf("rk[%d]=%d\n",v,rk[v]);
		}
	}
	pnode_stk top=dfs_stack+1;
	top->u=0,top->i=sn[0],f[0]=0,g[0]=0;
	while(top>dfs_stack)
		if(top->i==sn[top->u+1]){
		    --top;
//			uint t=f[top->u]+1;
//			t<f[(--top)->u]&&(f[top->u]=t);
		}
		else{
			uint v=c[top->i],t1=f[top->u]+1;
			int t2=g[top->u];
//			printf("%u %u\n",top->u,v);
			++top->i;
			++top,g[v]=min(t2,int((f[v]=s[v]?min(t1,t2+rk[v]+1):t1)-rk[v]));
//			printf("%u: %u %u\n",v,f[v],g[v]);
			top->u=v,top->i=sn[v];
		}
	for(uint i=1; i<=n; ++i)
		printf("%u\n",f[arr[i]]);
	return 0;
}