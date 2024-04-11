#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
const LL P = 1e9+7;
const int N = 2e5+10;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp1[N], dp2[N]; //dp1: min extra space; dp2: num of "big enough"
int out[N], in[N], tmp[N], a[N], n, cnt=0;
vector<int> l[N];

int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",out+i,in+i);
	memcpy(tmp, out, sizeof tmp);
	sort(tmp+1,tmp+n+1);
	unordered_map<int, int> id;
	rep(i,1,n)if(tmp[i]!=tmp[i-1]){
		a[++cnt] = tmp[i];
		id[tmp[i]] = cnt;
	}
	
	rep(i,1,n)l[id[out[i]]].PB(in[i]);
	dp1[0] = 0; dp2[0] = 1;
	int minsp = 1e9, maxl = *max_element(in+1, in+n+1);
	
	rep(i,1,cnt){
		dp1[i] = dp1[i-1] + a[i] - a[i-1];
		for(auto x:l[i]){
			int j = upper_bound(a, a+cnt+1, x) - a - 1;
			dp1[i] = min(dp1[i], dp1[j] + x - a[j]);
		}
		for(auto x:l[i]){
			int j = upper_bound(a, a+cnt+1, x) - a - 1;
			if(dp1[i] == dp1[j] + x - a[j]){
				dp2[i] = (dp2[i] + dp2[j]) % P;
			}
		}
		if(dp1[i] == dp1[i-1] + a[i] - a[i-1]) dp2[i] = (dp2[i] + dp2[i-1]) % P;
		if(a[i]>maxl) minsp = min(minsp, dp1[i]);
	}
	int ans = 0;
	rep(i,1,cnt)
		if(a[i]>maxl && dp1[i]==minsp) ans = (ans + dp2[i]) % P;
	printf("%d\n",ans);
	return 0;
}