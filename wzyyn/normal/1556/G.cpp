#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=200005;
int n,Q,tp[N],vit[N],ans[N],vis[N],fa[N];
long long x[N],y[N],q[N],qq[N];
vector<int> op[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void Add(ll nl,ll nr,int k){
	int pnl=upper_bound(qq+1,qq+*qq+1,nl)-qq-1;
	int pnr=upper_bound(qq+1,qq+*qq+1,nr)-qq-1;
	for (int p=pnl;p<=pnr;p++) if (vis[p]) fa[get(k)]=get(p);
}
int main(){
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=Q;i++){
		char s[10];
		scanf("%s%lld%lld",s+1,&x[i],&y[i]);
		tp[i]=(s[1]=='b'?1:2);
		if (tp[i]==1) q[++*q]=x[i],q[++*q]=y[i]+1;
	}
	q[++*q]=0; q[++*q]=1ll<<n;
	sort(q+1,q+*q+1);
	*q=unique(q+1,q+*q+1)-q-1;
	for (int i=1;i<=*q;i++) vit[i]=Q+1,fa[i]=i;
	for (int i=1;i<=Q;i++) if (tp[i]==1){
		int l=lower_bound(q+1,q+*q+1,x[i])-q;
		int r=lower_bound(q+1,q+*q+1,y[i]+1)-q-1;
		for (l=get(l);l<=r;l=get(l)) vit[l]=i,fa[l]=l+1;
	}
	for (int i=1;i<*q;i++) op[vit[i]].push_back(i); 
	for (int i=1;i<*q;i++){
		long long l=q[i],r=q[i+1]-1;
		qq[++*qq]=l; qq[++*qq]=r+1; 
		for (long long v=1;v<1ll<<n;v<<=1){
			if (l&v) l+=v;
			if (!(r&v)) r-=v;
			if (r==l-1) break;
		}
		qq[++*qq]=l;
	}
	sort(qq+1,qq+*qq+1);
	*qq=unique(qq+1,qq+*qq+1)-qq-1;
	for (int i=1;i<=*qq;i++) fa[i]=i;
	tp[Q+1]=1;
	for (int i=Q+1;i>=1;i--)
		if (tp[i]==1){
			for (auto j:op[i]){
				int l=lower_bound(qq+1,qq+*qq+1,q[j])-qq;
				int r=lower_bound(qq+1,qq+*qq+1,q[j+1])-qq-1;
				for (int k=l;k<=r;k++){
					ll v=1; vis[k]=1;
					for (;v<qq[k+1]-qq[k];v<<=1);
					Add((qq[k+1]-1)/v*v,(qq[k+1]-1)/v*v+v-1,k);
					for (;v<1ll<<n;v<<=1) Add(qq[k]^v,(qq[k+1]-1)^v,k);
				}
			}
		}
		else{
			int pS=upper_bound(qq+1,qq+*qq+1,x[i])-qq-1;
			int pT=upper_bound(qq+1,qq+*qq+1,y[i])-qq-1;
			ans[i]=(get(pS)==get(pT));
		}
	for (int i=1;i<=Q;i++)
		if (tp[i]==2) printf("%d\n",ans[i]);
}