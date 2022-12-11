#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long n,t,fa[N],l[N],r[N],ans;
struct edge{
    int to,nxt;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nxt=h[st];
    h[st]=cnt;
}
long long dfs(long long x){
	if(!h[x]){
        ans++;
        return r[x];
    }
	long long res=0;
	for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        res+=dfs(v);
    }
	if(res<l[x]){
        ans++;
        return r[x];
    }
    res=min(res,r[x]);
	return res;
}
int main(){
    scanf("%lld",&t);
	while(t--){
        scanf("%lld",&n);
        ans=cnt=0;
        for(int i=1;i<=n;i++)h[i]=0;
        for(int i=2;i<=n;i++)scanf("%lld",&fa[i]);
        for(int i=1;i<=n;i++)scanf("%lld%lld",&l[i],&r[i]);
        for(int i=2;i<=n;i++)add(fa[i],i);
        dfs(1);
        printf("%lld\n",ans);
    }
	return 0;
}