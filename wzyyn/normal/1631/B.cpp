#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int a[N];
void solve(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int r=n,re=0;
	for (;r>1&&a[r-1]==a[n];--r);
	for (;r>1;++re){
		r=n-2*(n-r+1)+1;
		for (;r>1&&a[r-1]==a[n];--r);
	}
	cout<<re<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}