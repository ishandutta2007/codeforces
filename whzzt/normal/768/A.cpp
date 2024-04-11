#include "bits/stdc++.h"
using namespace std;

const int N = 100005;
int a[N],n,l,r; 

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(l=1;l<n&&a[l+1]==a[l];l++);
	for(r=n;r>1&&a[r-1]==a[r];r--);
	cout<<max(r-l-1,0)<<endl;
	return 0;
}