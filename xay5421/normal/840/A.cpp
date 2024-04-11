#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005;
int n,a[N],b[N],id[N],ans[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	iota(id+1,id+n+1,1);
	sort(id+1,id+n+1,[&](int x,int y){return b[x]<b[y];});
	rep(i,1,n){
		ans[id[i]]=a[n+1-i];
	}
	rep(i,1,n)printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}