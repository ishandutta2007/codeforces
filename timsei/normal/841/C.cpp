#include<bits/stdc++.h>
using namespace std;

const int  N = 1000005;

struct NODE {
	int val , id;
}a[N] , b[N];

bool cmp(NODE xxx, NODE yyy) {
	return xxx.val<yyy.val;
}

int n , ans[N];
int main() {
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++) scanf("%d",&a[i].val);
	for(int i = 1;i <= n;i ++) scanf("%d",&b[i].val);
	for(int i = 1;i <= n;i ++) {
		a[i].id = b[i].id = i;
	}
	sort(a+ 1, a+n+1,cmp);
	sort(b + 1, b+n+1,cmp);
	for(int i = n;i >= 1;i--) {
		ans[b[n + 1 - i].id] = a[i].val;
	}
	for(int i = 1;i <= n;i ++) printf("%d ",ans[i]);
	puts("");
}