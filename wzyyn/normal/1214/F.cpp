#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=400005;
int q1[N],q2[N];
int mat[N],n,m,top;
pii a[N],q[N];
ll sum;
int op(int x){
	return x<0?-1:1;
}
void push_mat(int x,int y){
	if (x>y) swap(x,y);
	if (x==-n-1&&y==n+1) return;
	if (x==-n-1) q1[++*q1]=y;
	else if (y==n+1) q2[++*q2]=-x;
	else mat[y]=-x;
}
void push(pii x){
	if (top&&op(q[top].se)!=op(x.se)){
		sum+=x.fi-q[top].fi;
		push_mat(q[top].se,x.se);
		--top;
	}
	else q[++top]=x;
}
ll Func(int cnt){
	top=*q1=*q2=sum=0;
	if (cnt>=0){
		For(i,1,cnt)
			push(pii(0,-n-1));
	}
	else{
		For(i,1,-cnt)
			push(pii(0,n+1));
	}
	For(i,1,2*n)
		push(a[i]);
	if (cnt>=0){
		For(i,1,cnt)
			push(pii(m,n+1));
	}
	else{
		For(i,1,-cnt)
			push(pii(m,-n-1));
	}
	assert(*q1==*q2);
	For(i,1,*q1) mat[q1[i]]=q2[i];
	//printf("Func %d %d %lld\n",cnt,top,sum);
	return sum;
}
int main(){
	scanf("%d%d",&m,&n);
	For(i,1,n) scanf("%d",&a[i].fi),a[i].se=i;
	For(i,1,n) scanf("%d",&a[i+n].fi),a[i+n].se=-i;
	sort(a+1,a+2*n+1);
	int l=-n,r=n;
	while (l<r){
		//printf("%d %d\n",l,r);
		int mid=(l+r+2*n)/2-n;
		if (Func(mid)<=Func(mid+1)) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",Func(l));
	For(i,1,n) printf("%d ",mat[i]);
}