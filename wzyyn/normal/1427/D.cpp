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
int n,top;
int a[55],p[55];
vector<int> ans[55];
bool solve(){
	For(i,1,n) p[a[i]]=i;
	int x=-1,y=-1,t=-1;
	For(i,1,n-1)
		if (p[i+1]<p[i])
			x=p[i+1],y=p[i];
	if (x==-1) return 0;
	For(i,x,y-1)
		if (a[i]>a[i+1])
			t=i;
	++top;
	if (x!=1) ans[top].PB(x-1);
	ans[top].PB(t-x+1);
	ans[top].PB(y-t);
	if (y!=n) ans[top].PB(n-y);
	int p1=n,p2=0;
	for (auto i:ans[top]){
		p1-=i;
		For(j,1,i) p[p1+j]=a[p2+j];
		p2+=i;
	}
	//cout<<x<<' '<<y<<' '<<t<<endl; 
	For(j,1,n) a[j]=p[j];
	//cout<<a[j]<<' ';
	//cout<<endl;
	return 1;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	for (;solve(););
	printf("%d\n",top);
	For(i,1,top){
		printf("%d",ans[i].size());
		for (auto j:ans[i])
			printf(" %d",j);
		puts("");
	}
}