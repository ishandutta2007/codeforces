// author: xay5421
// created: Fri Jun  4 23:38:33 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
int T;
int main(){
	scanf("%d",&T);
	while(T--){
		int a[4];
		rep(i,0,3)scanf("%d",&a[i]);
		pair<int,int>cur=minmax(max(a[0],a[1]),max(a[2],a[3]));
		sort(a,a+4);
		if(cur==make_pair(a[2],a[3]))puts("YES");else puts("NO");
	}
	return 0;
}