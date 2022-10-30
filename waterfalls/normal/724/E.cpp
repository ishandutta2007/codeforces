#include <bits/stdc++.h>
using namespace std;

long long n,c,b,a[10013],i,cur,ans;
priority_queue<long long> mv;

int main() {
	cin>>n>>c;
	for (i=0;i<n;i++) cin>>a[i];
	cur=accumulate(a,a+n,0LL);
	for (i=0;i<n;i++) {
		cin>>b;
		mv.push(a[i]-b-(n-i-1)*c);
	}
	ans=cur;
	for (i=0;i<n;i++) {
		cur-=mv.top()+i*c;
		mv.pop();
		ans=min(ans,cur);
	}
	cout<<ans;
}