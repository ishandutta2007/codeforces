// author: xay5421
// created: Sat Jan 23 09:11:11 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=500005;
int n,a[N],id[N],t[N*4],ch[N],ans1=-1e9,ans2[N];
set<int>p;
void bud(int k1,int k2,int k3){
	if(k2==k3){t[k1]=k2&1;return;}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	t[k1]=t[k1*2]+t[k1*2+1];
}
void mdf(int k1,int k2,int k3,int k4){
	if(k2==k3){
		t[k1]^=1;
		return;
	}
	int mid=(k2+k3)>>1;
	if(k4<=mid)mdf(k1*2,k2,mid,k4);else mdf(k1*2+1,mid+1,k3,k4);
	t[k1]=t[k1*2]+t[k1*2+1];
}
int sum,pos,pd;
void getleft(int k1,int k2,int k3,int k5){
	if(k2>k5)return;
	if(k3<=k5){
		pd=1;
		if(sum+t[k1]==0||sum+t[k1]==k5-k2+1){
			sum+=t[k1];
			pos=k2;
			return;
		}
	}
	if(k2==k3)return;
	int mid=(k2+k3)>>1;
	getleft(k1*2+1,mid+1,k3,k5);
	if(!pd||pos==mid+1)getleft(k1*2,k2,mid,k5);
}
void getright(int k1,int k2,int k3,int k4){
	if(k3<k4)return;
	if(k4<=k2){
		pd=1;
		if(sum+t[k1]==0||sum+t[k1]==k3-k4+1){
			sum+=t[k1];
			pos=k3;
			return;
		}
	}
	if(k2==k3)return;
	int mid=(k2+k3)>>1;
	getright(k1*2,k2,mid,k4);
	if(!pd||pos==mid)getright(k1*2+1,mid+1,k3,k4);
}
void setx(int l,int r,int x){
	for(auto it=p.lower_bound(l);;){
		if(it==p.end()||*it>r)break;
		ans2[*it]=x;
		p.erase(it++);
	}
}
void work(int i,int x){
	pd=0,sum=0,pos=-1;
	getleft(1,1,n,i);
	int l=pos;
	
	pd=0,sum=0,pos=-1;
	getright(1,1,n,i);
	int r=pos;
	
	if(ch[l]==1&&ch[r]==1){
		setx(l,r,x);
	}else if(ch[l]==1){
		setx(l,(l+r)/2,x);
	}else if(ch[r]==1){
		setx((l+r)/2+1,r,x);
	}
}
void ps(int i){
	ch[i]^=1;
	mdf(1,1,n,i);
	work(i,a[i]);
	if(i>1)work(i-1,a[i]);
	if(i<n)work(i+1,a[i]);
}
void up2(int i){
	pd=0,sum=0,pos=-1;
	getleft(1,1,n,i);
	int l=pos;
	
	pd=0,sum=0,pos=-1;
	getright(1,1,n,i);
	int r=pos;
	
	ans1=max(ans1,(r-l)/2);
}
void up(int i){
	up2(i);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	bud(1,1,n);
	rep(i,1,n)scanf("%d",&a[i]),id[i]=i,p.insert(i);
	sort(id+1,id+1+n,[&](int x,int y){return a[x]>a[y];});
	rep(i,1,n){
		ps(id[i]);
	}
	for(int i=1,j;i<=n;i=j){
		j=i+1;
		while(a[id[i]]==a[id[j]])++j;
		rep(k,i,j-1)ps(id[k]);
		rep(k,i,j-1){
			up(id[k]);
		}
	}
	printf("%d\n",ans1);
	rep(i,1,n)printf("%d ",ans2[i]);
	puts("");
	return 0;
}