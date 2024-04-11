#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

typedef long long ll;

int n,q;
int A[100013];

stack<int> solve;
int a[100013];
int b[100013];
void query(int l, int r) {
        for (int i=l;i<=r;i++) a[i] = r+1;
        for (int i=l;i<=r;i++) b[i] = l-1;
        while (solve.size()>0) solve.pop();
        for (int i=r;i>=l;i--) {
            while (solve.size()>0 && A[i]>=A[solve.top()]) {
                b[solve.top()] = i;
                solve.pop();
            }
            solve.push(i);
        }
        while (solve.size()>0) solve.pop();
        for (int i=l;i<=r;i++) {
            while (solve.size()>0 && A[i]>A[solve.top()]) {
                a[solve.top()] = i;
                solve.pop();
            }
            solve.push(i);
        }
        ll ans = 0;
        for (int i=l;i<=r;i++) {
			ans+=(ll) A[i]*(i-b[i])*(a[i]-i);
        }
        printf("%lld\n",ans);
}

int main() {
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=1;i<n;i++) A[i] = abs(A[i+1]-A[i]);
	for (int Q=0;Q<q;Q++) {
		int l,r;
		scanf("%d%d",&l,&r);
		r-=1;
		query(l,r);
	}

	return 0;
}