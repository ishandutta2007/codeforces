#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

struct data{
	int l,r,id;
	bool operator<(const data &rhs)const {
		return l!=rhs.l ? l<rhs.l : id<rhs.id;
	}
}arr[1001];
int n,res[1001];

int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d%d",&arr[i].l,&arr[i].r),arr[i].id=i;
		arr[n].l=100000;

		int ct=1,j=0;
		for(int i=0;i<=n;i++) {
			while(j<i && ct<arr[i].l) {
				if(arr[j].r < ct) res[j]=0;
				else res[j]=ct++;
				j++;
			}
			ct=arr[i].l;
		}
		for(int i=0;i<n;i++) printf("%d ",res[i]);
		puts("");
	}
	return 0;
}