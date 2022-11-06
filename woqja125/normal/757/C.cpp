#include<stdio.h>
#include<vector>
#include<set>
#include<map>
using namespace std;
int c[1000001], l[1000001], in[100001];
map<int, int> ci[1000001];
vector<set<int>> S;
const int MOD = 1000000007;
long long fact(int x){
	long long re=1;
	for(int i=1; i<=x; i++) re = re*i%MOD;
	return re;
}
int main()
{
	int n, m, g;
	scanf("%d%d", &n, &m);
	S.push_back(set<int>());
	for(int i=1; i<=m; i++)S.front().insert(i);
	for(int i=1; i<=n; i++){
		scanf("%d", &g);
		for(int j=1; j<=g; j++){
			scanf("%d", in+j);
			c[in[j]]++;
		}
		for(int j=1; j<=g; j++){
			int x = in[j];
			if(c[x]<=0) continue;
			
			if(ci[l[x]].count(c[x]) == 0){
				ci[l[x]][c[x]] = S.size();
				S.push_back(set<int>());
			}
			int nl = ci[l[x]][c[x]];
			S[l[x]].erase(x);
			S[nl].insert(x);

			c[x] = -l[x];
			l[x]=nl;

		}
		for(int j=1; j<=g; j++){
			ci[-c[in[j]]].clear();
			c[in[j]] = 0;
		}
	}
	long long ans = 1;
	for(auto &s:S){
		ans = ans * fact(s.size()) % MOD;
	}
	printf("%lld", ans);	
	return 0;
}