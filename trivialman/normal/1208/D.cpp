#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;
const int N = 2e5+5;
 
int n, ans[N], fa[N];
LL s[N], tr[N];
 
void add(int x,LL val){ for(;x<=n;x+=x&-x)tr[x]+=val;}
LL get(int x){ LL res=0; for(;x;x-=x&-x)res+=tr[x]; return res; }
 
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",s+i);
	rep(i,1,n)add(i,i);
	rrep(i,n,1){
		int l=0,r=n,mid;
		while(l<=r){
			mid=l+r>>1;
			if(get(mid)<=s[i]) l=mid+1; else r=mid-1, ans[i]=mid;
		}
		add(ans[i],-ans[i]);
	}
	rep(i,1,n) printf("%d ",ans[i]);
	return 0;
}