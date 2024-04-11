#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=500005;
vector<int> ans[N];
int a[N],b[N],n,top;
int Func(int x){
	int sum=0;
	For(i,1,top)
		sum+=min(b[i],x);
	return sum/x;
}
void construct(int x){
	int py=1,sx=1,sum=0;
	For(i,1,top) if (b[i]>=x)
		For(j,1,x) ans[j].PB(a[i]);
	For(i,1,top) if (b[i]<x)
		For(j,1,b[i]){
			ans[py].PB(a[i]);
			py=py%x+1;
			if (py==sx) py=sx=py%x+1;
		}
	For(i,1,top) sum+=min(b[i],x);
	sum/=x;
	printf("%d\n%d %d\n",sum*x,x,sum);
	For(i,1,x){
		For(j,0,sum-1) printf("%d ",ans[i][(i+sum-j)%sum]);
		puts("");
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	top=1; b[1]=1;
	For(i,2,n){
		if (a[i]!=a[i-1])
			a[++top]=a[i];
		++b[top];
	}
	//For(i,1,top) printf("%d %d\n",a[i],b[i]);
	int ans=-1,id;
	for (int i=1;i*i<=n;i++){
		int val=Func(i);
		//printf("%d %d\n",i,val);
		if (val>=i&&val*i>ans) ans=val*i,id=i;
	}
	construct(id);
}
/*
9
1 1 1 2 2 3 3 4 4
9
2 4 1 2 4
3 1 2 3
1 3 4
*/