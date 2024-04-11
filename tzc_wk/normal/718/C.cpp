#include <bits/stdc++.h>
using namespace std;
#define int long long
const int YYQ=1e9+7;
struct matrix{
	int a[2][2];
	matrix(){memset(a,0,sizeof(a));}
	matrix operator *(matrix m){
		matrix ans;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int s=0;s<2;s++)
					ans.a[i][j]=(ans.a[i][j]+a[i][s]*m.a[s][j]%YYQ)%YYQ;
		return ans;
	}
	matrix operator +(matrix x){
		matrix ans;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				ans.a[i][j]=(ans.a[i][j]+a[i][j]+x.a[i][j])%YYQ;
		return ans;
	}
};
matrix pow(matrix x,int e){
	matrix ans;
	ans.a[0][0]=1,ans.a[0][1]=0;
	ans.a[1][0]=0,ans.a[1][1]=1;
	while(e){
		if(e&1)	ans=ans*x;
		x=x*x;
		e/=2;
	}
	return ans;
}
matrix fib_matrix(int n){
	matrix x;
	x.a[0][0]=1;x.a[0][1]=1;
	x.a[1][0]=1;x.a[1][1]=0;
	x=pow(x,n-1);
	return x;
}
struct node{
	int l,r;
	matrix val,add;
} s[400040];
int n,T;
int a[100005];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;
	matrix &x=s[k].add;
	x.a[0][0]=1;x.a[0][1]=0;
	x.a[1][0]=0;x.a[1][1]=1;
	if(l==r){
		s[k].val=fib_matrix(a[l]);
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	s[k].val=s[k<<1].val+s[k<<1|1].val;
}
void pushdown(int k){
	s[k<<1].val=s[k<<1].val*s[k].add;
	s[k<<1].add=s[k<<1].add*s[k].add;
	s[k<<1|1].val=s[k<<1|1].val*s[k].add;
	s[k<<1|1].add=s[k<<1|1].add*s[k].add;
	matrix &x=s[k].add;
	x.a[0][0]=1;x.a[0][1]=0;
	x.a[1][0]=0;x.a[1][1]=1;
}
void change(int k,int l,int r,matrix F){
	if(l<=s[k].l&&s[k].r<=r){
		s[k].val=s[k].val*F;
		s[k].add=s[k].add*F;
		return;
	}
	pushdown(k);
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid)			change(k<<1,l,r,F);
	else if(l>mid)		change(k<<1|1,l,r,F);
	else				change(k<<1,l,mid,F),change(k<<1|1,mid+1,r,F);
	s[k].val=s[k<<1].val+s[k<<1|1].val;
}
matrix query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r){
		return s[k].val;
	}
	pushdown(k);
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid)			return query(k<<1,l,r);
	else if(l>mid)		return query(k<<1|1,l,r);
	else				return query(k<<1,l,mid)+query(k<<1|1,mid+1,r);
}
signed main(){
	cin>>n>>T;
	for(int i=1;i<=n;i++)	cin>>a[i];
	build(1,1,n);
	while(T--){
		int type;cin>>type;
		if(type==1){
			int l,r,x;cin>>l>>r>>x;
			change(1,l,r,fib_matrix(x+1));
		}
		else{
			int l,r;cin>>l>>r;
			cout<<query(1,l,r).a[0][0]%YYQ<<endl;
		}
	}
}