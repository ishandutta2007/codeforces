#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=600005;
int n,m,q[N],f[N],fr[N],vis[N];
vector<pair<int,int>> op[N];
pair<int,int> t[N*4],tg[N*4];
void change(int k,int l,int r,int x,int y,pair<int,int> v){
	t[k]=max(t[k],v);
	if (x<=l&&r<=y) return tg[k]=max(tg[k],v),void(0);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
}
pair<int,int> ask(int k,int l,int r,int x,int y){
	if (x<=l&&r<=y) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return max(tg[k],ask(k*2,l,mid,x,y));
	if (x>mid) return max(tg[k],ask(k*2+1,mid+1,r,x,y));
	return max(tg[k],max(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y)));
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int tp,l,r;
		scanf("%d%d%d",&tp,&l,&r);
		q[++*q]=l; q[++*q]=r+1;
		op[tp].push_back(pair<int,int>(l,r));
	}
	sort(q+1,q+*q+1);
	*q=unique(q+1,q+*q+1)-q-1;
	int p=0;
	for (int i=1;i<=n;i++){
		pair<int,int> tmp(0,0);
		for (auto j:op[i]){
			int pl=lower_bound(q+1,q+*q+1,j.first)-q;
			int pr=lower_bound(q+1,q+*q+1,j.second+1)-q-1;
			tmp=max(tmp,ask(1,1,*q,pl,pr));
		}
		f[i]=tmp.first+1;
		if (f[i]>f[p]) p=i;
		fr[i]=tmp.second;
		for (auto j:op[i]){
			int pl=lower_bound(q+1,q+*q+1,j.first)-q;
			int pr=lower_bound(q+1,q+*q+1,j.second+1)-q-1;
			change(1,1,*q,pl,pr,pair<int,int>(f[i],i));
		}
	}
	for (int i=p;i;i=fr[i]) vis[i]=1;
	printf("%d\n",n-f[p]);
	for (int i=1;i<=n;i++)
		if (!vis[i]) printf("%d ",i);
}