#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=1005;
int n,tg[N*2];
ll a[N],q[N*2];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++)
		a[i]=a[i-1]+(i&1?a[i]:-a[i]);
	for (int i=0;i<=n;i++){
		q[++*q]=a[i]-1;
		q[++*q]=a[i];
	}
	sort(q+1,q+*q+1);
	*q=unique(q+1,q+*q+1)-q-1;
	tg[lower_bound(q+1,q+*q+1,0)-q]=1;
	ll ans=0;
	for (int i=1;i<=n;i++){
		int x=lower_bound(q+1,q+*q+1,a[i-1])-q;
		int y=lower_bound(q+1,q+*q+1,a[i])-q;
		if (x<y)
			for (int j=x+1;j<=y;j++) ++tg[j];
		else{
			for (int j=x-1;j>=y;j--) ans+=1ll*tg[j]*(q[j]-q[j-1]);
			for (int j=x;j>=y+1;j--) tg[j]=0;
			++tg[y];
		}
	}
	cout<<ans<<endl;
	
}