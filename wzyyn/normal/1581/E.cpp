#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,Q;
int x[N],y[N],clk[N],tag[N];
int v[505][505],ans,sum;
void change(int id,int t,int nt,int v){
	sum+=v;
	if (x[id]+y[id]>500){
		if ((nt-t)%(x[id]+y[id])<x[id]) ans+=v;
		for (;;){
			tag[t]+=v;
			if ((t+=x[id])>Q) break;
			tag[t]-=v;
			if ((t+=y[id])>Q) break;
		}
	}
	else{
		int cic=x[id]+y[id];
		t%=cic;
		for (int i=1;i<=x[id];i++){
			::v[cic][t]+=v;
			if ((++t)==cic) t=0;
		}
	}
}
int ask(int t){
	int tmp=ans;
	for (int i=1;i<=500;i++)
		tmp+=v[i][t%i];
	return sum-tmp;
}
int main(){
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for (int i=1;i<=Q;i++){
		int tp,x;
		scanf("%d%d",&tp,&x);
		ans+=tag[i];
		if (tp==1) change(x,clk[x]=i,i,1);
		else change(x,clk[x],i,-1);
		printf("%d\n",ask(i)); 
	}
}