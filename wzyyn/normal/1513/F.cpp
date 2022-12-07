#include<bits/stdc++.h>
using namespace std;

const int N=400005;
int n,top;
int a[N],b[N],q[N],v[N];
long long ans,delta;

struct node{
	int v;
	int id;
	int type;
	bool operator <(const node &a)const{
		return v<a.v; 
	}
}op[N];

struct ZKW{
	long long a[N*3];
	int nn;
	void build(int n){
		for (nn=1;nn<=n;nn<<=1);
		for (int i=0;i<=2*nn-1;i++) a[i]=1ll<<60;
	}
	void change(int p,long long v){
		for (p+=nn;p;p>>=1)
			a[p]=min(a[p],v);
	}
	long long ask(int l,int r){
		long long ans=1ll<<60;
		l+=nn-1; r+=nn+1;
		for (;l^r^1;l>>=1,r>>=1){
			if (!(l&1)) ans=min(ans,a[l^1]);
			if (r&1)	ans=min(ans,a[r^1]);
		} 
		return ans;
	}
}T1,T2;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	
	for (int i=1;i<=n;i++){
		q[++*q]=a[i];
		q[++*q]=b[i];
		v[i]=abs(a[i]-b[i]);
		ans+=v[i];
	}
	
	sort(q+1,q+*q+1);
	*q=unique(q+1,q+*q+1)-q-1;
	for (int i=1;i<=n;i++){
		a[i]=lower_bound(q+1,q+*q+1,a[i])-q;
		b[i]=lower_bound(q+1,q+*q+1,b[i])-q;
		op[++top]=(node){a[i],i,1};
		op[++top]=(node){b[i],i,0};
	}
	sort(op+1,op+top+1);
	
	T1.build(*q);
	T2.build(*q);
	for (int i=1;i<=top;i++){
		int x=op[i].id;
		if (op[i].type==1){
			T1.change(b[x],-1ll*v[x]-q[b[x]]-q[a[x]]);
			T2.change(b[x],-1ll*v[x]+q[b[x]]-q[a[x]]);
		}
		if (op[i].type==0){
			delta=min(delta,T1.ask(1, a[x])+q[a[x]]+q[b[x]]-v[x]);
			delta=min(delta,T2.ask(a[x],*q)-q[a[x]]+q[b[x]]-v[x]);
		}
		//cout<<i<<' '<<x<<' '<<op[i].id<<' '<<delta<<endl;
	}
	
	//cout<<delta<<endl;
	//cout<<ans<<endl;
	T1.build(*q);
	T2.build(*q);
	for (int i=top;i>=1;i--){
		int x=op[i].id;
		if (op[i].type==1){
			T1.change(b[x],-1ll*v[x]-q[b[x]]+q[a[x]]);
			T2.change(b[x],-1ll*v[x]+q[b[x]]+q[a[x]]);
		}
		if (op[i].type==0){
			delta=min(delta,T1.ask(1, a[x])+q[a[x]]-q[b[x]]-v[x]);
			delta=min(delta,T2.ask(a[x],*q)-q[a[x]]-q[b[x]]-v[x]);
		}
	}
	cout<<ans+delta<<endl;
	
}