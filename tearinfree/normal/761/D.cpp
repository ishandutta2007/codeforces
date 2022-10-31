#include <stdio.h>
#include <utility>
#include <algorithm>

struct Node
{
	int a, p ,idx,b;
	Node() {}
};

int n, l, r;
Node arr[100000];

bool cmp(const Node &a, const Node &b) {
	return a.p<b.p;
}
bool cmp_idx(const Node &a, const Node &b) {
	return a.idx<b.idx;
}

int main()
{
	scanf("%d %d %d",&n,&l,&r);
	for(int i=0;i<n;i++) 
		scanf("%d",&arr[i].a);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i].p);
		arr[i].idx=i;
	}

	std::sort(arr, arr+n,cmp);

	int prev=-2e9;
	for(int i=0;i<n;i++) {
		prev=std::max(prev+1, l-arr[i].a);
		if(prev>r-arr[i].a) {
			printf("-1\n");
			return 0;
		}
		arr[i].b=prev+arr[i].a;
	}
	std::sort(arr, arr+n,cmp_idx);
	for(int i=0;i<n;i++)
		printf("%d ",arr[i].b);

	return 0;
}