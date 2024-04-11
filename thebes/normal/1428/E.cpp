#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define F first
#define S second
#define pb push_back

const int MN = 1e5+5;
int N, K, T, i, arr[MN], cnt[MN]; ll ans;
ll cost(int n,int k){
	int hm = arr[n]/k;
	int res = arr[n]%k;
	return 1LL*hm*hm*(k-res)+1LL*(hm+1)*(hm+1)*res;
}
struct pq{bool operator()(const pll&i,const pll&j){return i.F<j.F;}};
priority_queue<pll,vector<pll>,pq> q;

int main(){
	scanf("%d%d",&N,&K);
	for(i=1;i<=N;i++){
		scanf("%d",&arr[i]);
		cnt[i] = 1;
		if(cnt[i]<arr[i]){
			q.push({cost(i,cnt[i])-cost(i,cnt[i]+1),i});
		}
	}
	T = K-N;
	while(T--){
		auto cur = q.top(); q.pop();
		cnt[cur.S] ++;
		if(cnt[cur.S]<arr[cur.S]){
			q.push({cost(cur.S,cnt[cur.S])-cost(cur.S,cnt[cur.S]+1),cur.S});
		}
	}
	for(i=1;i<=N;i++)
		ans += cost(i, cnt[i]);
	printf("%lld\n",ans);
	return 0;
}