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


#define ldb long double
int main(){
	ll n;
	scanf("%lld",&n);
	ll l1=0,l2=n+1,l3=n+1;
	ll r1=0,r2=n+1,r3=n+1;
	for (;;){
		ll X,Y;
		ldb sa=(ldb)(l2-l1)*(r2-r1);
		ldb sb=(ldb)(l2-l1)*(r3-r2);
		ldb sc=(ldb)(l3-l2)*(r2-r1);
		if (sc>=sa+sb) X=l2,Y=(r1+r2)/2;
		else if (sb>=sa+sc) X=(l1+l2)/2,Y=r2;
		else X=(l1+l2)/2,Y=(r1+r2)/2;
		printf("%lld %lld\n",X,Y);
		fflush(stdout);
		int k;
		scanf("%d",&k);
		if (k==0) return 0;
		if (k==1) l1=max(l1,X+1);
		if (k==2) r1=max(r1,Y+1);
		if (k==3) l2=min(l2,X),r2=min(r2,Y);
		if (l2<=l1) l2=l3,r3=r2;
		if (r2<=r1) r2=r3,l3=l2;
	}
}