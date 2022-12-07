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
const int N=5000005;
const ll inf=1000000000000000000ll;
int n,a[10005];
ll q1[N],q2[N];
void get_seq(int l,int r,ll *q,ll v){
	if (l>r) return q[++*q]=v,void(0);
	for (;;){
		get_seq(l+1,r,q,v);
		if (inf/v<a[l]) break;
		v*=a[l];
	}
}
ll check(ll v){
	ll ans=0,p=*q2;
	For(i,1,*q1){
		for (;p&&v/q1[i]<q2[p];--p);
		ans+=p;
	}
	//cout<<v<<' '<<ans<<endl;
	return ans;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	for (;clock()<30;) random_shuffle(a+1,a+n+1);
	get_seq(1,n/2,q1,1);
	get_seq(n/2+1,n,q2,1); 
	sort(q1+1,q1+*q1+1);
	sort(q2+1,q2+*q2+1);
	//For(i,1,*q1) cout<<q1[i]<<' '; cout<<endl;
	//For(i,1,*q2) cout<<q2[i]<<' '; cout<<endl;
	ll l=1,r=inf,ans=0,k;
	scanf("%lld",&k);
	while (l<=r){
		ll mid=(l+r)/2;
		if (check(mid)>=k)
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
}