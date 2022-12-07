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
int n,d,m;
ll q1[100005];
ll q2[100005];
int main(){
	scanf("%d%d%d",&n,&d,&m);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		if (x>m) q1[++*q1]=x;
		else q2[++*q2]=x;
	}
	ll ans=0;
	sort(q1+1,q1+*q1+1,greater<int>());
	sort(q2+1,q2+*q2+1,greater<int>());
	int l1=*q1,l2=*q2; *q1=*q2=0;
	For(i,1,l1) q1[i]+=q1[i-1];
	For(i,1,l2) q2[i]+=q2[i-1];
	For(i,0,l1){
		ll need=max(0ll,1ll*(i-1)*d);
		need-=min(need,1ll*(l1-i));
		if (need<=l2) ans=max(ans,q1[i]+q2[l2-need]);
	}
	cout<<ans;
}