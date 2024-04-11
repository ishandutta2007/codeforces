#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> BBST;

int q;
map<int,BBST> add;
map<int,BBST> sub;

int main() {
	scanf("%d",&q);
	while (q--) {
		int a,t,x;
		scanf("%d%d%d",&a,&t,&x);
		if (a==1) {
			add[x].insert(t);
		} else if (a==2) {
			sub[x].insert(t);
		} else {
			printf("%d\n",add[x].order_of_key(t)-sub[x].order_of_key(t));
		}
	}

	return 0;
}