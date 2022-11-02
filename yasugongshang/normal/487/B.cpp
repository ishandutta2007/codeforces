#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=200005;
int tree[4*N];
int f[N],n,s,l,dp[N],zhan4[N],a[N],zhan1[N],zhan2[N],zhan3[N],l1,r1,l2,r2,oo=1000000000;
inline int ask(int l,int r,int i,int j,int nod){
    int mid=(l+r)>>1;
	if (l==i&&j==r) return tree[nod];
	if (j<=mid) return ask(l,mid,i,j,nod<<1);
	else if(i>mid) return ask(mid+1,r,i,j,(nod<<1)+1);
	int left=ask(l,mid,i,mid,nod<<1);
	int right=ask(mid+1,r,mid+1,j,(nod<<1)+1);
	return min(left,right);
}
inline void insert(int l,int r,int i,int nod){
	int mid=(l+r)>>1;
	if (l==r) {tree[nod]=dp[l];return;}
	if (i<=mid)insert(l,mid,i,nod<<1);
	else insert(mid+1,r,i,(nod<<1)+1);
	tree[nod]=min(tree[nod<<1],tree[(nod<<1)+1]);
}
inline int	read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
int main(){
	n=read(); s=read(); l=read();
	int j=0;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		while(zhan1[l1]>a[i]+s&&l1<=r1){j=max(zhan2[l1],j);l1++;}
		while(zhan3[l2]<a[i]-s&&l2<=r2){j=max(zhan4[l2],j);l2++;}
		f[i]=j+1;
		while(zhan2[l1]<=j&&l1<=r1)l1++; while(zhan4[l2]<=j&&l2<=r2)l2++;
		while(zhan1[r1]<a[i]&&l1<=r1)r1--; while(zhan3[r2]>a[i]&&l2<=r2)r2--;
		zhan1[++r1]=a[i]; zhan2[r1]=i; zhan3[++r2]=a[i]; zhan4[r2]=i;//cout<<zhan3[l2]<<" "<<zhan4[l2]<<" "<<l2<<" "<<r2<<" "<<j<<endl;
	}
	for(int i=1;i<=n;i++){
		if(f[i]<=i-l)dp[i]=ask(1,n,f[i],i-l,1)+1; else dp[i]=oo; if(f[i]-1<=i-l)dp[i]=min(dp[i],dp[f[i]-1]+1); insert(1,n,i,1);// cout<<f[i]<<" "<<dp[i]<<endl;
	}
	if(dp[n]>=(oo>>1)){
		puts("-1");
	}else{
		writeln(dp[n]); 
	}
}/*
5 2 2
1 3 4 3 2*/