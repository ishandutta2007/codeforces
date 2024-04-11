#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int mod = 1e9+7;

struct query{
	int x,i;
	query() {}
	query(int x,int i):x(x), i(i) {}
};

int n,q,arr[100000],ans[100000],has[1<<20];
vector<query> qa[100000];
vector<int> t;

int main() {
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++) scanf("%d",arr+i);
	for(int i=0;i<q;i++) {
		int l,x;
		scanf("%d%d",&l,&x);
		l--;
		qa[l].push_back(query(x,i));
	}

	int val = 1;
	has[0]  = 1;
	t.push_back(0);
	
	for(int i=0;i<n;i++) {
		if(has[arr[i]]) val = (val * 2)%mod;
		else {
			int s=t.size();
			for(int j=0;j<s;j++) {
				has[arr[i]^t[j]] = 1;
				t.push_back(arr[i] ^ t[j]);
			}
		}
		for(auto &it:qa[i]) {
			if(has[it.x]) ans[it.i] = val;
			else ans[it.i] =0;
		}
	}
	for(int i=0;i<q;i++) printf("%d\n",ans[i]);
	
	return 0;
}