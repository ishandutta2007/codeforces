#include<iostream>
#include<queue>
using namespace std;
const int N=1e5+1;
int mod,phi;
int pfc;
int pf[11],pc[11];
int n;
int bit[11][N];
void bupd(int t,int id,int v){
	for(int i=id; i<=n ;i+=i&-i) bit[t][i]+=v;
}
int bqry(int t,int id){
	int res=0;
	for(int i=id; i>=1 ;i-=i&-i) res+=bit[t][i];
	return res;
}
int a[N];
int b[N];
int pv[11];
int sa[262144],la[262144];
int sb[262144],lb[262144];
int pw(int x,int y){
	if(y==0) return 1;
	if(y%2) return 1LL*x*pw(x,y-1)%mod;
	int res=pw(x,y/2);
	return 1LL*res*res%mod;
}
void pusha(int id){
	sa[id*2]=1LL*sa[id*2]*la[id]%mod;
	sa[id*2+1]=1LL*sa[id*2+1]*la[id]%mod;
	la[id*2]=1LL*la[id*2]*la[id]%mod;
	la[id*2+1]=1LL*la[id*2+1]*la[id]%mod;
	la[id]=1;
}
void upda(int id,int l,int r,int ql,int qr,int x){
	if(l>qr || r<ql) return;
	if(ql<=l && r<=qr){
		sa[id]=1LL*sa[id]*x%mod;
		la[id]=1LL*la[id]*x%mod;
		return;
	}
	pusha(id);
	int mid=(l+r)/2;
	upda(id*2,l,mid,ql,qr,x);
	upda(id*2+1,mid+1,r,ql,qr,x);
	sa[id]=(sa[id*2]+sa[id*2+1])%mod;
}
void upd2a(int id,int l,int r,int p,int x){
	if(l==r){
		sa[id]=x%mod;
		return;
	}
	pusha(id);
	int mid=(l+r)/2;
	if(p<=mid) upd2a(id*2,l,mid,p,x);
	else upd2a(id*2+1,mid+1,r,p,x);
	sa[id]=(sa[id*2]+sa[id*2+1])%mod;
}
void pushb(int id){
	sb[id*2]=1LL*sb[id*2]*lb[id]%mod;
	sb[id*2+1]=1LL*sb[id*2+1]*lb[id]%mod;
	lb[id*2]=1LL*lb[id*2]*lb[id]%mod;
	lb[id*2+1]=1LL*lb[id*2+1]*lb[id]%mod;
	lb[id]=1;
}
void updb(int id,int l,int r,int ql,int qr,int x){
	if(l>qr || r<ql) return;
	if(ql<=l && r<=qr){
		sb[id]=1LL*sb[id]*x%mod;
		lb[id]=1LL*lb[id]*x%mod;
		return;
	}
	pushb(id);
	int mid=(l+r)/2;
	updb(id*2,l,mid,ql,qr,x);
	updb(id*2+1,mid+1,r,ql,qr,x);
	sb[id]=(sb[id*2]+sb[id*2+1])%mod;
}
void upd2b(int id,int l,int r,int p,int x){
	if(l==r){
		sb[id]=x%mod;
		return;
	}
	pushb(id);
	int mid=(l+r)/2;
	if(p<=mid) upd2b(id*2,l,mid,p,x);
	else upd2b(id*2+1,mid+1,r,p,x);
	sb[id]=(sb[id*2]+sb[id*2+1])%mod;
}
int qrya(int id,int l,int r,int ql,int qr){
	if(l>qr || r<ql) return 0;
	if(ql<=l && r<=qr) return sa[id];
	pusha(id);
	int mid=(l+r)/2;
	return (qrya(id*2,l,mid,ql,qr)+qrya(id*2+1,mid+1,r,ql,qr))%mod;
}
int qryb(int id,int l,int r,int p){
	if(l==r) return sb[id];
	pushb(id);
	int mid=(l+r)/2;
	if(p<=mid) return qryb(id*2,l,mid,p);
	else return qryb(id*2+1,mid+1,r,p);
}
void build(int id,int l,int r){
	la[id]=lb[id]=1;
	if(l==r){
		sa[id]=a[l]%mod,sb[id]=b[l]%mod;
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	sa[id]=(sa[id*2]+sa[id*2+1])%mod;
	sb[id]=(sb[id*2]+sb[id*2+1])%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> mod;
	phi=mod;
	int tzuyu=mod;
	for(int i=2; i*i<=tzuyu ;i++){
		if(tzuyu%i==0){
			pf[++pfc]=i;
			phi=phi/i*(i-1);
			while(tzuyu%i==0){
				tzuyu/=i;pc[pfc]++;
			}
		}
	}
	if(tzuyu!=1){
		int i=tzuyu;
		pf[++pfc]=i;
		phi=phi/i*(i-1);
		while(tzuyu%i==0){
			tzuyu/=i;pc[pfc]++;
		}
	}
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		b[i]=a[i];
		for(int j=1; j<=pfc ;j++){
			int cur=0;
			while(b[i]%pf[j]==0) ++cur,b[i]/=pf[j];
			bupd(j,i,cur-pv[j]);pv[j]=cur;
		}
	}
	build(1,1,n);
	int q;cin >> q;
	for(int i=1; i<=q ;i++){
		int t,l,r,x;
		cin >> t;
		if(t==1){
			cin >> l >> r >> x;
			int y=x;
			for(int j=1; j<=pfc ;j++){
				int cur=0;
				while(y%pf[j]==0) ++cur,y/=pf[j];
				bupd(j,l,cur);
				if(r!=n) bupd(j,r+1,-cur);
			}
			upda(1,1,n,l,r,x);
			updb(1,1,n,l,r,y);
		}
		else if(t==2){
			cin >> l >> x;
			int num=qryb(1,1,n,l);
			int num2=num;
			int y=x;
			for(int j=1; j<=pfc ;j++){
				int cur=0;
				while(y%pf[j]==0) ++cur,y/=pf[j];
				bupd(j,l,-cur);
				if(l!=n) bupd(j,l+1,cur);
				num=1LL*num*pw(pf[j],bqry(j,l))%mod;
			}
			int num3=pw(y,phi-1);
			num=1LL*num*num3%mod;
			num2=1LL*num2*num3%mod;
			upd2a(1,1,n,l,num);
			upd2b(1,1,n,l,num2);
		}
		else{
			cin >> l >> r;
			cout << qrya(1,1,n,l,r) << '\n';
		}
	}
}