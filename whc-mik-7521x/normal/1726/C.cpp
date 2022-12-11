#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int t,n,tl[N],vis[N];
map<int,int>p;
char s[N];
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
void ad(int x,int y){
    add(x,y);
    add(y,x);
}
void dfs(int x){
	if(vis[x])return;
	vis[x]=1;
	for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        dfs(v);
    }
}
int main(){
    scanf("%d",&t);
	while(t--){
        cnt=0;
        scanf("%d",&n);
        n<<=1;
        for(int i=1;i<=n;i++)h[i]=0,vis[i]=0;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            if(s[i]=='(') tl[i]=tl[i-1]+1;
            else tl[i]=tl[i-1]-1;
        }
        p[0]=0;
        for(int i=1;i<=n;i++){
            if(p.count(tl[i])&&s[i]==')') ad(p[tl[i]]+1,i);
            if(i==n) continue;
            if(s[i]==')'&&s[i+1]=='(') ad(i,i+1);
            if(s[i+1]=='(') p[tl[i]]=i;
        }
        int ans=0;
        for(int i=1;i<=n;i++)if(!vis[i]) dfs(i),ans++;
        printf("%d\n",ans);
    }
	return 0;
}