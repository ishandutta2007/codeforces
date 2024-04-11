#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=100005;
int n,fa[N],dep[N],cnt[N];
int main(){
	scanf("%d",&n);
	cnt[dep[1]]^=1;
	rep(i,2,n)scanf("%d",&fa[i]),dep[i]=dep[fa[i]]+1,cnt[dep[i]]^=1;
	printf("%d\n",(int)count(cnt,cnt+n+1,1));
	return 0;
}