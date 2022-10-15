#include<bits/stdc++.h>
#define first F
#define second S
using namespace std;

const int maxn=200007;
int t,n,cnt[maxn];
vector<int> vec[maxn];
long long ans=0;
priority_queue<int,vector<int>,greater<int> >pq;
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		ans=0;
		while (pq.size()) pq.pop();
		for (int i=0;i<n;++i){
			vec[i].clear();
		}
		for (int i=0;i<n;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			vec[u].push_back(v);
		}
		for (int i=n-1;i>-1;--i){
			for (auto c:vec[i]){
				pq.push(c);
			}
			while (pq.size()>n-i){
				ans+=pq.top();
				pq.pop();
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}