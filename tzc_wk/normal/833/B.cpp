#include <bits/stdc++.h>
using namespace std;
int n,a[35005],dp[52][35005],pos[35005],pre[35005],k;
struct node{
	int l,r,val,add;
} s[140020];
void pushdown(int k){
	s[k<<1].val+=s[k].add;
	s[k<<1].add+=s[k].add;
	s[k<<1|1].val+=s[k].add;
	s[k<<1|1].add+=s[k].add;
	s[k].add=0;
}
void build(int k,int l,int r,int t){
	s[k].l=l;s[k].r=r;s[k].add=0;
	if(l==r){
		s[k].val=dp[t][l-1];
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid,t);
	build(k<<1|1,mid+1,r,t);
	s[k].val=max(s[k<<1].val,s[k<<1|1].val);
}
void update(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r){
		s[k].val++;
		s[k].add++;
		return;
	}
	pushdown(k);
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid)			update(k<<1,l,r);
	else if(l>mid)		update(k<<1|1,l,r);
	else				update(k<<1,l,mid),update(k<<1|1,mid+1,r);
	s[k].val=max(s[k<<1].val,s[k<<1|1].val);
}
int query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r){
		return s[k].val;
	}
	pushdown(k);
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid)			return query(k<<1,l,r);
	else if(l>mid)		return query(k<<1|1,l,r);
	else				return max(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pos[a[i]]+1;
		pos[a[i]]=i;
	}
	for(int i=1;i<=k;i++){
		build(1,1,n,i-1);
		for(int j=1;j<=n;j++){
			update(1,pre[j],j);
			dp[i][j]=query(1,1,j);
		}
	}
	cout<<dp[k][n]<<endl;
}