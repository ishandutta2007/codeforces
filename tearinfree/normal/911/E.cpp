#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int n,m,arr[200001];

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) scanf("%d",arr+i);

	stack<int> stk;
	int cur=1;
	for(int i=0;i<m;i++) {
		if(!stk.empty() && stk.top() < arr[i]) {
			puts("-1");
			return 0;
		}
		stk.push(arr[i]);
		while(!stk.empty() && stk.top()==cur) stk.pop(),cur++;
	}

	for(int i=0;i<m;i++) printf("%d ",arr[i]);
	while(!stk.empty()) {
		vector<int> res;
		while(cur < stk.top()) {
			res.push_back(cur++);
		}
		for(int i=(int)res.size()-1;i>=0;i--) printf("%d ",res[i]);
		stk.pop(); cur++;
	}
	vector<int> res;
	while(cur<=n) {
		res.push_back(cur++);
	}
	for(int i=(int)res.size()-1;i>=0;i--) printf("%d ",res[i]);
	
	return 0;
}