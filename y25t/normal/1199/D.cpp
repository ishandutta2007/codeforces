#include<cstdio>
#include<algorithm>
#define N 200005

int n,a[N],m;

int t[N<<3];
inline void change(int p,int L,int R,int pos,int x){
	if(pos<L||pos>R)
		return;
	if(L==R){
		t[p]=0;
		a[pos]=x;
		return;
	}
	t[p<<1]=std::max(t[p<<1],t[p]);
	t[p<<1|1]=std::max(t[p<<1|1],t[p]);
	t[p]=0;
	int mid=(L+R)>>1;
	change(p<<1,L,mid,pos,x);
	change(p<<1|1,mid+1,R,pos,x); 
}
inline void upd(int p,int L,int R){
	if(L==R){
		a[L]=std::max(a[L],t[p]);
		return;
	}
	t[p<<1]=std::max(t[p<<1],t[p]);
	t[p<<1|1]=std::max(t[p<<1|1],t[p]);
	int mid=(L+R)>>1;
	upd(p<<1,L,mid);
	upd(p<<1|1,mid+1,R);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int op;
		scanf("%d",&op);
		if(op==1){
			int pos,x;
			scanf("%d%d",&pos,&x);
			change(1,1,n,pos,x);
		}
		else{
			int x;
			scanf("%d",&x);
			t[1]=std::max(t[1],x);
		}
	}
	upd(1,1,n);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
}