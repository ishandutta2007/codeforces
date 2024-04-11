#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
int n;ll w;
struct node{
	ll w;int id;
	friend bool operator <(node x,node y){
		return x.w<y.w;
	}
} a[200005];
void solve(){
	scanf("%d%lld",&n,&w);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i].w),a[i].id=i;
	sort(a+1,a+n+1);ll sum=0;
	vector<int> v;
	for(int i=1;i<=n;i++){
		sum+=a[i].w;v.pb(a[i].id);
		if(sum>=(w+1)/2&&sum<=w){
			sort(v.begin(),v.end());
			printf("%d\n",v.size());
			ffe(it,v) printf("%d ",*it);printf("\n");
			return;
		}
		if(a[i].w>=(w+1)/2&&a[i].w<=w){
			printf("1\n%d\n",a[i].id);
			return;
		}
	}
	puts("-1");
}
int main(){
	int T;scanf("%d",&T);
	while(T--) solve();
	return 0;
}