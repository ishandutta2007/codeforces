// author: xay5421
// created: Mon Jun 14 19:03:03 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const int N=3005;
int n,a[N];
priority_queue<int>q;
LL ans;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]),a[i]-=i;
	q.push(a[1]);
	rep(i,2,n){
		q.push(a[i]);
		if(a[i]<q.top()){
			ans+=q.top()-a[i];
			q.pop();
			q.push(a[i]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}