#include <bits/stdc++.h>
using namespace std;
int n,i,j,k,l,r,m,x,y;
const int N=200000;
pair<int,int> a[N+1];
int main(){
	for(cin>>n>>k;i<n;i++)cin>>x,a[x].first++,a[x].second=x;
	sort(a,a+N+1);
	for(x=0,l=1,r=n;l+1<r;){
		m=(l+r)/2;
		for(x=0,i=N;i>0;i--)x+=a[i].first/m;
		x>=k?l=m:r=m;
	}
	for(i=N;i>0;i--)
		for(j=a[i].first/l;j>0&&k-->0;j--)
			cout<<a[i].second<<" ";
}