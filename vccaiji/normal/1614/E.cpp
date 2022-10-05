#include<bits/stdc++.h>
using namespace std;
const int V=1000000000;
struct node{
	int lc,rc,num;
}a[19198100];
int tot=0;
int newnode(){
	a[++tot].lc=0;
	a[tot].rc=0;
	a[tot].num=0;
	return tot;
}
void update(int x,int l,int r,int p){
	if(l==r){
		a[p].num++;
		return;
	}
	int md=(l+r)/2;
	if(x<=md){
		if(a[p].lc==0)a[p].lc=newnode();
		update(x,l,md,a[p].lc);
	}
	else{
		if(a[p].rc==0)a[p].rc=newnode();
		update(x,md+1,r,a[p].rc);
	}
	a[p].num++;
}
int sum(int x,int y,int l,int r,int p){
	if(y<x)return 0;
	if((x<=l)&&(y>=r))return a[p].num;
	int md=(l+r)/2,ans=0;
	if(x<=md && a[p].lc)ans+=sum(x,y,l,md,a[p].lc);
	if(y>=md+1 && a[p].rc)ans+=sum(x,y,md+1,r,a[p].rc);
	return ans;
}
int query(int x,int l,int r,int p){
	if(l==r)return l;
	if(p==0)return l+x-1;
	int md=(l+r)/2;
	int num=md-l+1;
	if(a[p].lc)num-=a[a[p].lc].num;
	if(num>=x)return query(x,l,md,a[p].lc);
	return query(x-num,md+1,r,a[p].rc);
}
int n;
int main(){
	int now=0,now2=V,lastans=0;
	scanf("%d",&n);
	newnode();
	for(int i=1;i<=n;i++){
		int t,k;
		scanf("%d%d",&t,&k);
		int q1,q2;
		if((t>now)&&(t<=now2))q1=query(t-now,1,V,1);
		if((t>=now)&&(t<now2))q2=query(t+1-now,1,V,1);
		if((t>now)&&(t<=now2))update(q1,1,V,1);
		if((t>=now)&&(t<now2))update(q2,1,V,1);
		if(t>now)now++;
		if(t<now)now--;
		if(t<now2)now2--;
		if(t>now2)now2++;
		for(int j=1;j<=k;j++){
			int q;
			scanf("%d",&q);
			q=(q+lastans)%1000000001;
			lastans=now+q-sum(1,q,1,V,1);
			printf("%d\n",lastans);
		}
	}
	return 0;
}