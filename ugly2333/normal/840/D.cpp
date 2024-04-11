//CF 840D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 333333;
const int inf = 1e9+37;
struct node{
	int sz;
	vector<int> v;
}T[N*4];
int a[N],ql[N],qr[N],qk[N];
vector<int> pos[N];
int k,ans[N];
int cnt(int x,int l,int r){
	return upper_bound(pos[x].begin(),pos[x].end(),r)-lower_bound(pos[x].begin(),pos[x].end(),l);
}
void upd(int x,int y,int l,int r){
	int i,len;
	len=r-l+1;
	for(i=0;i<T[y].sz;i=i+1)
		if(cnt(T[y].v[i],l,r)*k>len){
			//cout<<T[y].v[i]<<l<<r<<k<<endl;
			T[x].sz++;
			T[x].v.push_back(T[y].v[i]);
		}
}
void build(int x,int l,int r){
	if(l==r){
		T[x].sz++;
		T[x].v.push_back(a[l]);
		return;
	}
	int md;
	md=(l+r)>>1;
	build(x<<1,l,md);
	build(x<<1|1,md+1,r);
	upd(x,x<<1,l,r);
	upd(x,x<<1|1,l,r);
	sort(T[x].v.begin(),T[x].v.end());
	T[x].sz=unique(T[x].v.begin(),T[x].v.end())-T[x].v.begin();
}
void query(int L,int R,int x,int l,int r){
	if(L>R||L>r||l>R)
		return;
	if(L<=l&&r<=R){
		upd(0,x,L,R);
		return;
	}
	int md;
	md=(l+r)>>1;
	query(L,R,x<<1,l,md);
	query(L,R,x<<1|1,md+1,r);
}
int main()
{
	int n,q,i,j,o;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		pos[a[i]].push_back(i);
	}
	for(i=1;i<=q;i=i+1)
		scanf("%d%d%d",ql+i,qr+i,qk+i);
	for(j=2;j<=5;j=j+1){
		k=j;
		for(i=0;i<=4*n+5;i=i+1){
			T[i].sz=0;
			T[i].v.clear();
		}
		build(1,1,n);
		for(i=1;i<=q;i=i+1){
			if(qk[i]==j){
				ans[i]=inf;
				T[0].sz=0;
				T[0].v.clear();
				query(ql[i],qr[i],1,1,n);
				for(o=0;o<T[0].sz;o=o+1)
					ans[i]=min(ans[i],T[0].v[o]);//cout<<T[0].v[o]<<endl;//
				if(ans[i]==inf)
					ans[i]=-1;
			}
		}
	}
	for(i=1;i<=q;i=i+1)
		printf("%d\n",ans[i]);
	return 0;
}