#include"bits/stdc++.h"
using namespace std;
const int N=200005;
int a[N],n,ans,p[N],t,sz; bool vis[N];
int main(){
	cin >> n; 
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf ("%d",&p[i]);
	for (int i=1;i<=n;i++) if(!vis[i]){
		int x = i;
		for (; !vis[x]; x=a[x]) {
			vis[x]=true;
			if (p[x]==1) t++;
		}
		sz ++;
	}
	if (t%2==0) ans++;
	ans += sz==1 ? 0 : sz;
	cout << ans << endl;
	return 0;
}