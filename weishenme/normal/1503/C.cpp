#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
const int N=100005;
int n;
pii a[N];
int main(){
	long long ans=0;
	scanf("%d",&n);
	int last=0;
	for (int i=1;i<=n;i++)scanf("%d%d",&a[i].fi,&a[i].se),ans+=a[i].se,last=max(last,a[i].fi),a[i].fi+=a[i].se;
	sort(a+1,a+n+1);
	for (int i=n;i;i--){
		ans+=max(0,last-a[i].fi);
		last=min(last,a[i].fi-a[i].se);
	}
	printf("%lld\n",ans);
}