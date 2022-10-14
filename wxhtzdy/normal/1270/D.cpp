#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, k, vis[505], a[505];

PII ask(vector<int> ids)
{
	printf("? "); rep(i, k) printf("%d ", ids[i]); puts(""); fflush(stdout);
	PII ret;
	scanf("%d%d", &ret.first, &ret.second);
	return ret;
}

int main()
{
	scanf("%d%d", &n, &k);
	multiset<int> st;
	rep1(i, k + 1) {
		vector<int> ids;
		rep1(j, k + 1) if(i != j) ids.push_back(j);
		st.insert(ask(ids).second);
	}
	printf("! %d", st.count(*prev(st.end()))); fflush(stdout);
	return 0;
}