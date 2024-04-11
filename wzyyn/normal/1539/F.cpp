#include<bits/stdc++.h>
using namespace std;

const int N=200005;
int n,a[N],q[N],ans[N];
vector<int> v[N];

int Mymin(int x,int y){
	return x<y?x:y;
}
int Mymax(int x,int y){
	return x>y?x:y;
}

struct Seg{
	int (*f)(int,int)=NULL;
	int t[N*4],tg[N*4];
	
	void build(int k,int l,int r){
		tg[k]=0;
		if (l==r){
			t[k]=q[l];
			return;
		}
		int mid=(l+r)/2;
		build(k*2,l,mid);
		build(k*2+1,mid+1,r);
		t[k]=f(t[k*2],t[k*2+1]);
	}
	void addv(int k,int v){
		tg[k]+=v;
		t[k]+=v;
	}
	void pushdown(int k){
		if (!tg[k]) return;
		addv(k*2,tg[k]);
		addv(k*2+1,tg[k]);
		tg[k]=0; 
	}
	void build(int (*g)(int,int)){
		f=g;
		build(1,1,n);
	}
	void change(int k,int l,int r,int x,int y,int v){
		if (x<=l&&r<=y)	
			return addv(k,v);
		pushdown(k);
		int mid=(l+r)/2;
		if (x<=mid) change(k*2,l,mid,x,y,v);
		if (y>mid) change(k*2+1,mid+1,r,x,y,v);
		t[k]=f(t[k*2],t[k*2+1]); 
	}
	int ask(int k,int l,int r,int x,int y){
		if (x<=l&&r<=y)
			return t[k];
		pushdown(k);
		int mid=(l+r)/2;
		if (y<=mid) return ask(k*2,l,mid,x,y);
		if (x>mid) return ask(k*2+1,mid+1,r,x,y);
		return f(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y));
	}
}T1,T2,T3,T4;

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		v[a[i]].push_back(i);
	}
	for (int i=1;i<=n;i++) q[i]=(i%2==0?i/2 - i:-(1<<25));
	T1.build(Mymax);
	for (int i=1;i<=n;i++) q[i]=(i%2==1?(i+1)/2 - i:-(1<<25)); 
	T2.build(Mymax);
	for (int i=1;i<=n;i++) q[i]=(i+1)/2;
	T3.build(Mymax);
	for (int i=1;i<=n;i++) q[i]=i/2;
	T4.build(Mymax);
	for (int i=1;i<=n;i++){
		for (auto j:v[i]){
			ans[j]=max(ans[j],T1.ask(1,1,n,1,j) + T3.ask(1,1,n,j,n));
			ans[j]=max(ans[j],T2.ask(1,1,n,1,j) + T4.ask(1,1,n,j,n));
		}
		for (auto j:v[i]){
			if (j!=n) T1.change(1,1,n,j+1,n,1);
			if (j!=n) T2.change(1,1,n,j+1,n,1);
			T3.change(1,1,n,j,n,-1);
			T4.change(1,1,n,j,n,-1);
		}
	}
	
	//for (int i=1;i<=n;i++)
	//	printf("%d ",ans[i]);
	for (int i=1;i<=n;i++) q[i]=(i%2==0?-(i/2)+(i-1):-(1<<25));
	T1.build(Mymax);
	for (int i=1;i<=n;i++) q[i]=(i%2==1?-((i+1)/2)+(i-1):-(1<<25)); 
	T2.build(Mymax);
	for (int i=1;i<=n;i++) q[i]=-((i+1)/2);
	T3.build(Mymax);
	for (int i=1;i<=n;i++) q[i]=-(i/2);
	T4.build(Mymax);
	for (int i=1;i<=n;i++){
		for (auto j:v[i]){
			if (j!=n) T1.change(1,1,n,j+1,n,-1);
			if (j!=n) T2.change(1,1,n,j+1,n,-1);
			T3.change(1,1,n,j,n,1);
			T4.change(1,1,n,j,n,1);
		}
		for (auto j:v[i]){
			ans[j]=max(ans[j],T1.ask(1,1,n,1,j) + T3.ask(1,1,n,j,n));
			ans[j]=max(ans[j],T2.ask(1,1,n,1,j) + T4.ask(1,1,n,j,n));
			//cout<<j<<' '<<T4.ask(1,1,n,j,n)<<' '<<T2.ask(1,1,n,1,j)<<endl;
		}
	}
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}
/*
0/1

(r-l+1+s1)
*/