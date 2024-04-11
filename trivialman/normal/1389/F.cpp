#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
 
int n, l, r, t, ans = 0;
array<int, 3> a[200005];
 
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d%d",&l,&r,&t);
		a[i] = {r,l,t-1};
	}
	sort(a+1,a+n+1);
	
	multiset<int> st[2];
	rep(i,1,n){
		t = a[i][2];
		auto it = st[t^1].lower_bound(a[i][1]);
		if (it == st[t^1].end())
			st[t].insert(a[i][0]);
		else
			st[t^1].erase(it), ans++;
	}
	cout<<n-ans<<endl;
}