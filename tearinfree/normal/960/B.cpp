#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <string>
#include <iostream>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

int n,k1,k2;
lli a[1000],b[1000];
struct data{
	lli val;
	lli i,j;
	data() {}
	data(lli val,lli i,lli j){
		this->val=val;
		this->i=i;
		this->j=j;
	}
	bool operator<(const data &rhs)const {
		return val<rhs.val;
	}
};
int main() {
	lli sum=0;
	scanf("%d%d%d",&n,&k1,&k2);

	priority_queue<data> que;
	for(int i=0;i<n;i++) {
		scanf("%lld",a+i);
	}
	for(int i=0;i<n;i++) scanf("%lld",b+i);

	for(int i=0;i<n;i++) {
		lli aa=max(a[i],b[i]), bb=min(a[i],b[i]);
		sum += (aa-bb)*(aa-bb);
		que.push(data( (aa-bb)*(aa-bb), aa, bb));
	}

	k1+=k2;
	while(k1--) {
		data cur = que.top(); que.pop();

		sum -= cur.val;
		if(cur.val==0) cur.i++;
		else cur.i--;
		sum += (cur.i-cur.j) * (cur.i-cur.j);
		cur.val = (cur.i-cur.j) * (cur.i-cur.j);
		que.push(cur);
	}
	printf("%lld\n",sum);
	
	return 0;
}