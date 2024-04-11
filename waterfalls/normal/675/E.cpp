#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int a[100013];
ll val[100013];
int st[1<<18];

void build(int w, int L, int R) {
	if (L==R) st[w] = L;
	else {
		build(w*2,L,(L+R)/2), build(w*2+1,(L+R)/2+1,R);
		st[w] = (a[st[w*2]]>a[st[w*2+1]]) ? st[w*2] : st[w*2+1];
	}
}

int query(int w, int L, int R, int a, int b) {
	if (b<L || R<a) return 0;
	if (a<=L && R<=b) return st[w];
	int one = query(w*2,L,(L+R)/2,a,b);
	int two = query(w*2+1,(L+R)/2+1,R,a,b);
	return (::a[one]>::a[two]) ? one : two;
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<n;i++) scanf("%d",&a[i]);
	a[n] = n;
	build(1,1,n);
	for (int i=n;i>=1;i--) {
		int high = query(1,1,n,i,a[i]);
		val[i] = val[high]+n-i-(a[i]-high);
	}
	printf("%lld\n",accumulate(val,val+n+1,0LL));

	return 0;
}