#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
char s[N];
int n;
struct Tree{
	int l,r,num1,num2,sum,flag;
}T[N*4];
void build(int x,int l,int r){
	T[x].l=l;T[x].r=r;T[x].flag=-1;
	if (l==r)return;
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
}
inline void down(int x){
	if (T[x].flag!=-1){
		T[x*2].sum=(T[x*2].r-T[x*2].l+1)*T[x].flag;
		T[x*2+1].sum=(T[x*2+1].r-T[x*2+1].l+1)*T[x].flag;
		T[x*2].num1=T[x*2+1].num1=T[x*2].num2=T[x*2+1].num2=T[x].flag;
		T[x*2].flag=T[x].flag;
		T[x*2+1].flag=T[x].flag;
		T[x].flag=-1;
	}
}
inline void update(int x){
	T[x].num1=max(T[x*2].num1,T[x*2+1].num1);
	T[x].num2=min(T[x*2].num2,T[x*2+1].num2);
	T[x].sum=T[x*2].sum+T[x*2+1].sum;
}
inline void insert(int x,int l,int r,int z){
	if (T[x].l>r||l>T[x].r)return;
	if (T[x].l==T[x].r){
		T[x].num1=T[x].num2=T[x].sum=max(T[x].sum,z);
		return;
	}
	if (T[x].l>=l&&T[x].r<=r){
		if (T[x].num2>=z)return;
		if (T[x].num1<=z){
			T[x].num1=T[x].num2=T[x].flag=z;
			T[x].sum=(T[x].r-T[x].l+1)*z;
			return;
		}
	}
	down(x);
	insert(x*2,l,r,z);
	insert(x*2+1,l,r,z);
	update(x);
}
signed main(){
	scanf("%lld",&n);
	scanf("%s",s+1);
	int last=n+1,ans=0;
	build(1,1,n);
	for (int i=n;i;i--)
		if (s[i]=='1'){
			insert(1,last,n,last-i);
			ans+=T[1].sum+(last-i)*(last-i+1)/2;
		}
		else {
			for (int j=i+1;j<last;j++)insert(1,j,j,j-i);
			last=i;
			ans+=T[1].sum;
		}
	printf("%lld\n",ans);
}