#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int val[N],flag[N],x,y,n;
struct seg{
	struct Tree{
		int l,r,num,flag;
	}T[N*4];
	void build(int x,int l,int r){
		T[x].flag=-1;T[x].l=l;T[x].r=r;
		if (l==r)return;
		int mid=(l+r)/2;
		build(x*2,l,mid);
		build(x*2+1,mid+1,r);
	}
	void down(int x){
		if (T[x].flag!=-1){
			T[x*2].flag=T[x*2+1].flag=1;
			T[x*2].num=T[x*2+1].num=1e9;
			T[x].flag=-1;
		}
	}
	void insert1(int x,int l,int r){
		if (T[x].l>r||l>T[x].r)return;
		if (T[x].l>=l&&T[x].r<=r){
			T[x].num=1e9;
			T[x].flag=1;
			return;
		}
		down(x);
		insert1(x*2,l,r);
		insert1(x*2+1,l,r);
		T[x].num=min(T[x*2].num,T[x*2+1].num);
	}
	void insert2(int x,int y,int z){
		T[x].num=min(T[x].num,z);
		if (T[x].l==T[x].r)return;
		down(x);
		int mid=(T[x].l+T[x].r)/2;
		if (y<=mid)insert2(x*2,y,z);
		else insert2(x*2+1,y,z);
	}
	int find(int x,int l,int r){
		if (T[x].l>r||l>T[x].r)return 1e9;
		if (T[x].l>=l&&T[x].r<=r)return T[x].num;
		down(x);
		return min(find(x*2,l,r),find(x*2+1,l,r));
	}
}T0,T1;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		if (!((x>n)^(y>n))){
			puts("-1");
			return 0;
		}
		if (x>n)flag[min(x,y)]=1;
		val[min(x,y)]=max(x,y)-n;
	}
	T0.build(1,1,n+1);
	T1.build(1,1,n+1);
	int Min=n+1,num0=0,num1=0;
	for (int i=1;i<=n;i++){
		if (val[i]<Min){
			T0.insert2(1,Min,T1.find(1,1,n+1)+num1-num0);
			T1.insert2(1,Min,T0.find(1,1,n+1)+num0-num1);
			num0+=flag[i];num1+=flag[i]^1;
			Min=val[i];
		}
		else {
			int t1=T0.find(1,val[i]+1,n+1),t2=T1.find(1,val[i]+1,n+1);
			T0.insert1(1,1,n+1);
			T1.insert1(1,1,n+1);
			T0.insert2(1,val[i],t1+(flag[i]^1));
			T1.insert2(1,val[i],t2+(flag[i]));
		}
	}
	if (min(T0.T[1].num+num0,T1.T[1].num+num1)>=1e8)puts("-1");
	else printf("%d\n",min(T0.T[1].num+num0,T1.T[1].num+num1));
}