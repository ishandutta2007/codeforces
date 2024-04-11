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
const int N=300005;
int n,x[N],y[N];
char s[N*2];
pii check(int d){
	int l1=0,r1=1<<30;
	int l2=0,r2=1<<30;
	int l3=-(1<<30),r3=(1<<30);
	For(i,1,n){
		l1=max(l1,x[i]-d); r1=min(r1,x[i]+d);
		l2=max(l2,y[i]-d); r2=min(r2,y[i]+d);
		l3=max(l3,x[i]-y[i]-d); r3=min(r3,x[i]-y[i]+d);
	}
	if (l1>r1||l2>r2||l3>r3) return pii(-1,-1);
	if (r1-l2<l3||l1-r2>r3) return pii(-1,-1);
	//cout<<d<<' '<<l1<<' '<<l2<<' '<<l3<<' '<<r1<<' '<<r2<<' '<<r3<<endl; 
	int px=r1,py=r2;
	if (px-py<l3) py-=l3-(px-py);
	if (px-py>r3) px-=(px-py)-r3;
	return pii(px,py);
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%s",s+1);
		int l=strlen(s+1);
		For(j,1,l)
			(s[j]=='B'?x[i]++:y[i]++);
	}
	int l=0,r=1<<20,vv=0;
	pii ans;
	while (l<=r){
		int mid=(l+r)/2;
		pii v=check(mid);
		if (v.fi!=-1) vv=mid,ans=v,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",vv);
	For(i,1,ans.fi) putchar('B');
	For(i,1,ans.se) putchar('N');
}