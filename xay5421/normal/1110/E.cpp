// author: xay5421
// created: Sat Feb 20 21:52:53 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=100005;
int n,a[N],b[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)scanf("%d",&b[i]);
	if(a[1]!=b[1]||a[n]!=b[n])puts("No"),exit(0);
	rep(i,1,n-1){
		a[i]=a[i+1]-a[i];
		b[i]=b[i+1]-b[i];
	}
	sort(a+1,a+n),sort(b+1,b+n);
	if(vector<int>(a+1,a+n)==vector<int>(b+1,b+n))puts("Yes");else puts("No");
	return 0;
}