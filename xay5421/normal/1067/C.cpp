// author: xay5421
// created: Fri Oct  8 15:18:08 2021
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	vector<pair<int,int> >ans;
	int x=0;
	while(SZ(ans)<n){
		ans.eb(x,1);
		ans.eb(x,-1);
		ans.eb(x+1,0);
		x+=2;
	}
	rep(i,0,n-1)printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}