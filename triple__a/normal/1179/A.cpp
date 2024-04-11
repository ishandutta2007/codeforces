#include<iostream>
#include<cmath>
#include<algorithm>
#include<deque>
using namespace std;

const int maxn=300007;
int n,a[maxn],cnt=0;
pair<int,int> ans[maxn]; 
int main(){
	deque<int> q;
	q.clear();
	int m;
	scanf("%d%d",&n,&m);
	int mx=-1;
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		q.push_back(a[i]);
		mx=max(mx,a[i]);
	}
	while(1){
		int u,v;
		u=q.front();
		q.pop_front();
		v=q.front();
		q.pop_front();
		ans[++cnt]=make_pair(u,v);
		q.push_back(min(u,v));
		q.push_front(max(u,v));
		if (max(u,v)==mx) break;
	}
	int i=0;
	while(q.size()){
		a[++i]=q.front();
		q.pop_front();
	}
	while(m--){
		long long u;
		scanf("%lld",&u);
		if (u<=cnt){
			printf("%d %d\n",ans[u].first,ans[u].second);
		} 
		else{
			printf("%d %d\n",a[1],a[(u-cnt-1)%(n-1)+2]);
		}
	}
	return 0;
}