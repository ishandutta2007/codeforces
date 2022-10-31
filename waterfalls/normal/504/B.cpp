#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Tree;

int n;
int a[200013], b[200013];

void read(int p[]) {
	Tree has;
	for (int i=0;i<n;i++) has.insert(i);
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		p[i] = has.order_of_key(x);
		has.erase(x);
	}
}

void write(int p[]) {
	Tree has;
	for (int i=0;i<n;i++) has.insert(i);
	for (int i=0;i<n;i++) {
		int x = *has.find_by_order(p[i]);
		printf("%d ",x);
		has.erase(x);
	}
	printf("\n");
}

int main() {
	scanf("%d",&n);
	read(a);
	read(b);
	for (int i=n-1;i>=0;i--) {
		a[i]+=b[i];
		if (i) a[i-1]+=a[i]/(n-i);
		a[i]%=(n-i);
	}
	write(a);

	return 0;
}