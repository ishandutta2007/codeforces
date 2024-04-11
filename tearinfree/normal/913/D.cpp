#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <complex>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;
typedef long long lli;
typedef pair<lli, lli> pll;
typedef pair<int, int> pii;
const lli mod=1e9+7;
const lli inf=2e18;

inline int _abs(int a) {
	return a<0 ? -a : a;
}
inline lli _abs(lli a) {
	return a<0 ? -a : a;
}

struct data{
	int a,t,i;
	bool operator<(const data &rhs)const {
		return a<rhs.a;
	}
}arr[200000];
int n,t;
int main() {
	scanf("%d%d",&n,&t);
	for(int i=0;i<n;i++) scanf("%d%d",&arr[i].a,&arr[i].t),arr[i].i=i;
	sort(arr,arr+n);

	priority_queue<pii> que;
	int j=n-1,sum=0;
	for(int i=n;i;i--) {
		while(j>=0 && arr[j].a>=i) {
			sum+=arr[j].t;
			que.push(pii(arr[j].t,arr[j].i));
			j--;
		}
		while(que.size()>i) {
			sum-=que.top().first;
			que.pop();
		}
		if(que.size()>=i && t>=sum) {
			printf("%d\n%d\n",i,i);
			while(!que.empty()) {
				printf("%d ",que.top().second+1);
				que.pop();
			}
			return 0;
		}
	}
	printf("0\n0\n");
	
	return 0;
}