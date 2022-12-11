#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;
int n,m,k;

int v[N][N];
int h[N],q[N],a[N];

int BFS(long long &ans,int st){
    int top=1,bot=1;
    q[1]=st;
    h[st]=1;
    int nedge=0;
    while (top<=bot){
        int x=q[top++];
        for(int y=1;y<=n;y++) if (v[x][y]){
            nedge++;
            if (!h[y]){
                h[y]=1;
                q[++bot]=y;
            }
        }
    }
    ans+=1LL*bot*(bot-1)/2-nedge/2;
    return bot;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++) scanf("%d",a+i);
    while (m--){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x][y]=v[y][x]=1;
    }
    long long ans=0;
    int hub=0;
    for(int i=1;i<=k;i++)
        hub=max(hub,BFS(ans,a[i]));
    int rem=0;
    for(int i=1;i<=n;i++) if (!h[i]){
        int n1=BFS(ans,i);
        ans+=1LL*n1*rem;
        rem+=n1;
    }
    cout<<ans+1LL*hub*rem;
}