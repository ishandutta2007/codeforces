#include<bits/stdc++.h>

using namespace std;

const int N=500005;
char s[N];
int n,a[N],id[N],ans[N];
bool cmp(int x,int y){
	if (1ll*a[x]*y!=1ll*a[y]*x)
		return 1ll*a[x]*y<1ll*a[y]*x;
	return x<y;
}
void solve(){
	scanf("%d%s",&n,s+1);
	for (int i=1;i<=n;i++){
		a[i]=a[i-1]+(s[i]=='D');
		id[i]=i;
	}
	sort(id+1,id+n+1,cmp);
	ans[id[1]]=1;
	for (int i=2;i<=n;i++){
		ans[id[i]]=1;
		if (1ll*a[id[i]]*id[i-1]==1ll*a[id[i-1]]*id[i])
			ans[id[i]]=ans[id[i-1]]+1;
	}
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}