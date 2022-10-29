#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define N 300005
 
int n, m, x;
int tr[N<<1], l[N], r[N], pos[N];
 
void add(int x,int val){ for(;x<=n+m;x+=x&-x) tr[x] += val; }
int get(int x){int res=0; for(;x;x-=x&-x) res += tr[x]; return res;}
 
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n) l[i] = i;
	
	rep(i,1,n) add(pos[i]=m+i,1);
	rep(i,1,m){
	    scanf("%d",&x), l[x] = 1;
		int &p = pos[x];
		r[x] = max(r[x], get(p));
		add(p, -1), add(p=m+1-i, 1);
	}
	rep(i,1,n) r[i] = max(r[i], get(pos[i]));
	rep(i,1,n) printf("%d %d\n",l[i],r[i]);
	return 0;
}