#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <utility>
#include <cstring>

using namespace std;

char str[200100];
int n,arr[200000];

vector<vector<int>> ans;

int main() {
	scanf("%s",str);
	n=strlen(str);
	
	for(int i=0;i<n;i++) arr[i] = str[i]-'0';

	int f=1;
	stack<int> zs,os;
	for(int i=0;i<n;i++) {
		if(arr[i] == 0) {
			if(!os.empty()) {
				ans[os.top()].push_back(i+1);
				zs.push(os.top());
				os.pop();
			}
			else {
				ans.push_back(vector<int>());
				zs.push(ans.size()-1);
				ans.back().push_back(i+1);
			}
		}
		else {
			if(zs.empty()) {
				f=0;
				break;
			}
			else {
				ans[zs.top()].push_back(i+1);
				os.push(zs.top());
				zs.pop();
			}
		}
	}

	if(!os.empty()) f=0;
	if(!f) {
		puts("-1");
	}
	else {
		printf("%d\n",ans.size());
		for(auto &a:ans) {
			printf("%d ",a.size());
			for(auto &val:a) printf("%d ",val);
			puts("");
		}
	}
	
	return 0;
}