#include <bits/stdc++.h>
const int MAXN=100010;
using namespace std;
#define int long long
int f[MAXN],cnt[MAXN],a[MAXN],b[MAXN],visit[MAXN],ans[MAXN],n;
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void link(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy) f[fy]=fx;
	cnt[fx]+=cnt[fy];
}
main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
		f[i]=i;
    }
    for(int i=0;i<n;i++) cin>>b[i];
    int MAX=0;
    for(int i=n-1;i>=0;i--){
        cnt[b[i]]=a[b[i]],visit[b[i]]=1,ans[i]=MAX;
        if(b[i]!=1&&visit[b[i]-1]) link(b[i],b[i]-1);
        if(b[i]!=n&&visit[b[i]+1]) link(b[i],b[i]+1);
        MAX=max(MAX,cnt[find(b[i])]);
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<endl;
    return 0;
}