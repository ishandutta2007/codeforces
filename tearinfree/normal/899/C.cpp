#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int n;
int main() {
	scanf("%d",&n);
	
	int r=n%4;
	printf("%d\n", (r+1)%4/2);
	
	vector<int> res;
	int c=n/4;
	if(r==0) {
		for(int i=1;i<=c;i++) res.push_back(i);
		for(int i=n;i>n-c;i--) res.push_back(i);
	}
	else {
		res.push_back(r);
		
		for(int i=r+1;i<=r+c;i++) res.push_back(i);
		for(int i=n;i>n-c;i--) res.push_back(i);
	}
	printf("%d ",res.size());
	for(auto &val:res) printf("%d ",val);
	
	return 0;
}