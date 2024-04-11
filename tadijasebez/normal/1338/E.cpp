#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=8005;
bitset<N> E[N];
char s[N];
int in[N],f[N],cnt[N],n;
int main(){
    scanf("%i",&n);
    for(int i=1;i<=n;++i){
        scanf("%s",s);
        for(int j=0;j<n/4;++j){
            int st=j*4+1,B=0;
            if(s[j]<='9' && s[j]>='0')B=s[j]-'0';
		
            else B=s[j]-'A'+10;
            if(B&1)E[i].set(st+3);
            if(B>>1&1)E[i].set(st+2);
            if(B>>2&1)E[i].set(st+1);
            if(B>>3&1)E[i].set(st+0);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(E[i].test(j))
                in[j]++;
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(!in[i])
            q.push(i);
    int m=n;
    ll ans=0;
    while(q.size()){
        int u=q.front();q.pop();
        m--;ans+=(ll)614*n*m+m;
        f[u]=-1;
        for(int v=1;v<=n;v++){
            if(!E[u].test(v))continue;
            in[v]--;
            if(!in[v])
                q.push(v);
        }
    }
    if(!m)return 0*printf("%lld\n",ans);
    int x=1;
    for(int i=1;i<=n;i++)
        if(in[i]>in[x])
            x=i;
    for(int i=1;i<=n;i++)
        if(in[i])
            f[i]=E[x].test(i)?1:0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(f[i]+f[j]==1){
                if(E[i].test(j))cnt[j]++;
                else cnt[i]++;
            }
    for(int i=1;i<=n;i++)if(in[i])
        for(int j=i+1;j<=n;j++)if(in[j]){
            if(f[i]!=f[j])ans+=3;
            else ans+=cnt[i]==cnt[j]?4:3;
        }
    printf("%lld\n",ans);
    return 0;
}