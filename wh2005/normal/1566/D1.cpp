#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e5+9;
int T,n,m,a[N];
struct pp{int val,id;}p[N];

bool cmp(pp x,pp y){
	return x.val==y.val?(x.id>y.id):(x.val<y.val);
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++) scanf("%d",&a[i]);
		for(int i=1;i<=m;i++) p[i].val=a[i],p[i].id=i;
		sort(p+1,p+m+1,cmp);
		for(int i=1;i<=m;i++) a[p[i].id]=i;
		ll ans=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<i;j++) ans+=(a[j]<a[i]);
		}		
		printf("%lld\n",ans);
	}
	return 0;
}