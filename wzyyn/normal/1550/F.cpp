#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=200005;
int n,Q,s,d,top;
int a[N],ans[N],fa[N];
struct node{
	int tp,x,y,v;
	bool operator <(const node &a)const{
		return v==a.v?tp<a.tp:v<a.v; 
	}
}op[N*7];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int main(){
	scanf("%d%d%d%d",&n,&Q,&s,&d);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int p=1;
	for (int i=1;i<=n;i++){
		for (;p<=n&&a[i]+d>a[p];++p);
		if (p<=n) op[++top]=(node){1,i,p  ,abs(a[p  ]-a[i]-d)};
		if (p!=1) op[++top]=(node){1,i,p-1,abs(a[p-1]-a[i]-d)};
		if (p< n) op[++top]=(node){1,i,p+1,abs(a[p+1]-a[i]-d)};
	}
	p=1;
	for (int i=1;i<=n;i++){
		for (;p<=n&&a[i]-d>a[p];++p);
		if (p<=n) op[++top]=(node){1,i,p  ,abs(a[p  ]-a[i]+d)};
		if (p!=1) op[++top]=(node){1,i,p-1,abs(a[p-1]-a[i]+d)};
		if (p< n) op[++top]=(node){1,i,p+1,abs(a[p+1]-a[i]+d)};
	}
	for (int i=1;i<=Q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		op[++top]=(node){2,i,x,y};
	}
	sort(op+1,op+top+1);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=top;i++)
		if (op[i].tp==1)
			fa[get(op[i].x)]=get(op[i].y);
		else ans[op[i].x]=(get(s)==get(op[i].y));
	for (int i=1;i<=Q;i++)
		puts(ans[i]?"Yes":"No"); 
}