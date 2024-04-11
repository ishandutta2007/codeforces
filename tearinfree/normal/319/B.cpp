#include <cstdio>
#include <algorithm>
#include <stack>
#include <utility>

using namespace std;
typedef pair<int,int> pii;

int n,arr[100001],chk[100001];
int main() {
	stack<int> stk;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",arr+i);
	
	int m=0;
	for(int i=1;i<=n;i++) if(m<arr[i]){
		m=arr[i];
		chk[i]=1;
	}

	int mx=0;
	for(int i=n;i;i--) {
		if(chk[i]) while(!stk.empty()) stk.pop();
		else {
			while(!stk.empty() && stk.top() < arr[i]) {
				stk.pop();
			}
			stk.push(arr[i]);
			mx=max(mx,(int)stk.size());
		}
	}
	printf("%d\n",mx);
	return 0;
}