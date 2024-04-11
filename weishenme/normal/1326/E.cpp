#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int b[N],n,x;
struct Tree{
	int l,r,num,flag;
}T[N*4];
void build(int x,int l,int r){
	T[x].l=l;T[x].r=r;
	if (l==r){
		T[x].num=0;
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	T[x].num=max(T[x*2].num,T[x*2+1].num);
}
void down(int x){
	T[x*2].num+=T[x].flag;
	T[x*2+1].num+=T[x].flag;
	T[x*2+1].flag+=T[x].flag;
	T[x*2].flag+=T[x].flag;
	T[x].flag=0;
}
void insert(int x,int l,int r,int z){
	if (T[x].l>r||l>T[x].r)return;
	if (T[x].l>=l&&T[x].r<=r){
		T[x].num+=z;
		T[x].flag+=z;
		return;
	}
	down(x);
	insert(x*2,l,r,z);
	insert(x*2+1,l,r,z);
	T[x].num=max(T[x*2].num,T[x*2+1].num);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&x),b[x]=i;
	int ans=n;
	build(1,1,n);
	insert(1,1,b[ans],1);
	printf("%d\n",ans);
	for (int i=1;i<n;i++){
		scanf("%d",&x);
		insert(1,1,x,-1);
		while (T[1].num==0){
			ans--;
			insert(1,1,b[ans],1);
		}
		printf("%d ",ans);
	}
}