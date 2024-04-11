#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
const int B=300;
struct node{
	int to,s1,s2;
};
int n,Q,tp[N],x[N];
int vis[N],clr[N],in[N];
int fl[N],ofl[N];
vector<int> e[N];
vector<node> E[N];

void dfs1(int x,int fa=-1,int s1=0,int s2=0){
	if (vis[x]){
		if (fa!=-1) E[fa].PB((node){x,s1,s2});
		for (auto i:e[x]) dfs1(i,x,0,0);
	}
	else{
		s1+=(!fl[x]);
		for (auto i:e[x])
			dfs1(i,fa,s1,s2+1);
	}
}
void dfs2(int x,int fa=0,bool cl=0){
	//cout<<"D2 "<<x<<' '<<cl<<' '<<vis[x]<<' '<<fl[x]<<' '<<in[x]<<endl;
	if (vis[x])
		fa=in[x],cl|=clr[x];
	else{
		if (cl) fl[x]=0;
		if (!fl[x]&&fa)
			fl[x]=1,--fa;
	}
	for (auto i:e[x])
		dfs2(i,fa,cl);
} 
void make1(int x){
	//cout<<"WZP "<<x<<' '<<fl[x]<<endl;
	if (!fl[x]) return fl[x]=1,void(0);
	++in[x];
	for (auto i:E[x])
		if (i.s1+1<=in[x])
			make1(i.to);
}
void make2(int x){
	fl[x]=0; in[x]=0; clr[x]=1;
	for (auto &i:E[x])
		i.s1=i.s2,make2(i.to);
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,2,n){
		int x; 
		scanf("%d",&x);
		e[x].PB(i);
	}
	For(i,1,Q)
		scanf("%d%d",&tp[i],&x[i]);
	for (int l=1,r=B;l<=Q;l+=B,r+=B){
		r=min(r,Q);
		For(i,1,n){
			if (vis[i]) E[i].resize(0);
			vis[i]=clr[i]=in[i]=0;
		}
		For(i,l,r)
			vis[x[i]]=1;
		dfs1(1);
		For(i,l,r)
			if (tp[i]==1) make1(x[i]);
			else if (tp[i]==2) make2(x[i]);
			else puts(fl[x[i]]?"black":"white");
		dfs2(1);
		//For(i,1,n) cout<<fl[i]<<' '; cout<<endl;
	}
}