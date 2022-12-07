#include<bits/stdc++.h>

using namespace std;

int n,a[200005];
set<int> S; 
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	S.clear();
	S.insert(a[1]);
	S.insert(-(1<<30));
	S.insert(1<<30);
	for (int i=2;i<=n;i++){
		auto it=S.lower_bound(a[i-1]);
		auto pre=it,nxt=it;
		pre--; nxt++;
		if (a[i]<*pre||a[i]>*nxt){
			puts("NO");
			return;
		}
		S.insert(a[i]);
	}
	puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}