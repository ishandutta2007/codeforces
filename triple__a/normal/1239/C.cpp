#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn=100007;
int n,k;
vector<pair<ll,int> >vec;
ll ans[maxn];
priority_queue<int,vector<int>,greater<int> >wait;
queue<int> q;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;++i){
		ll u;
		scanf("%lld",&u);
		vec.push_back({u,i});
	}
	sort(vec.begin(),vec.end());
	ll t=0;
	int cnt=0,idx=0;
	while (cnt<n){
		if (wait.empty()&&q.empty()){
			t=vec[idx].first;
		}
		while (idx<n&&vec[idx].first<=t+k){
			if (q.empty()||q.back()>vec[idx].second){
				q.push(vec[idx++].second);
			} 
			else{
				wait.push(vec[idx++].second);
			}
		}
//		cout<<q.front()<<endl;
		t+=k;
		ans[q.front()]=t, q.pop();
		cnt++;
		if (q.empty()&& !wait.empty()){
			q.push(wait.top()), wait.pop();
		}
	}
	for (int i=1;i<=n;++i){
		printf("%lld\n",ans[i]);
	}
	return 0;
}