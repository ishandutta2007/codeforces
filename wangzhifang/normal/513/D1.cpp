#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define max_n 1000000
#define INF 2147483647
using namespace std;
typedef cs int& ci;
struct edge_node{
	int v,nxt;
	edge_node(){}
	edge_node(ci _v,ci _nxt):v(_v),nxt(_nxt){}
};
struct tree{
	int head[max_n+1],cnt;
	edge_node edge[max_n];
	void build(){
		memset(head,-1,sizeof(head)),cnt=-1;
	}
	void push(ci u,ci v){
		edge[++cnt]=edge_node(v,head[u]);
		head[u]=cnt;
	}
};
tree ltr,rtr;
int mxl[max_n+1],mnr[max_n+1],mxr[max_n+1],mxn[max_n+1];
int ans[max_n+1],*now;
void solve(ci l,ci r){
	if(l>r)
		return;
	if(mxl[l]){
		solve(l+1,mxl[l]);
		*++now=l;
		solve(mxl[l]+1,r);
	}
	else{
		*++now=l;
		solve(l+1,r);
	}
}
struct node{
	int val,pos;
	node(){}
	node(ci v,ci p):val(v),pos(p){}
};
template<typename _Tp>_Tp*lower_bound_greater(_Tp*__first,_Tp*__last,cs _Tp&__val){
	for(_Tp*__middle; (__middle=__first+((__last-__first)>>1))>__first; (*__middle>=__val?__first:__last)=__middle);
	return __first;
}
int pos[max_n+1],val[max_n+1],*nps,*nvl;
int main(){
	char op[6];
	int n,c;
	scanf("%d%d",&n,&c),now=ans,ltr.build(),rtr.build();
	for(int i=c+1,a,b; --i; (op[0]=='L'?ltr:rtr).push(a,b)){
		scanf("%d%d %s",&a,&b,op);
		if(b<=a){
			puts("IMPOSSIBLE");
			return 0;
		}
	}
	pos[0]=INF,val[0]=INF,mxl[n]=mxr[n],mnr[n]=INF,mxn[n]=n,pos[1]=n,val[1]=n,nps=pos+1,nvl=val+1;
	for(int i=n; --i; ){
		int&mxli=mxl[i],&mxri=mxr[i],&mnri=mnr[i];
		mxli=mxri=0,mnri=INF;
		for(int j=ltr.head[i],tmp; ~j; j=ltr.edge[j].nxt)
			(tmp=mxn[ltr.edge[j].v])>mxli&&(mxli=tmp);
		mxli&&(mxli=val[lower_bound_greater(pos+1,nps+1,mxli)-pos]);
		for(int j=i; ++j<=mxli; mxn[j]>mxli&&(mxli=mxn[j]));
		for(int j=rtr.head[i],tmp; ~j; j=rtr.edge[j].nxt){
			(tmp=rtr.edge[j].v)<mnri&&(mnr[i]=tmp);
			(tmp=mxn[tmp])>mxri&&(mxr[i]=tmp);
		}
		mxri&&(mxri=val[lower_bound_greater(pos+1,nps+1,mxri)-pos]);
		int mxni=(mxn[i]=mxri?mxri:(mxli?mxli:i));
		for(; mxni>*nvl; --nvl,--nps);
		*++nps=i,*++nvl=mxni;
//		printf("%d:mxl(%d),mnr(%d),mxr(%d),mxn(%d)\n",i,mxli,mnri,mxri,mxn[i]);
		if(mxli>=mnri){
			puts("IMPOSSIBLE");
			return 0;
		}
	}
	solve(1,n);
	for(int*i=ans; ++i<=now; printf("%d ",*i));
	return 0;
}