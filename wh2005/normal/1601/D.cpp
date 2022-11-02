#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int n,d;
struct pp{int s,a,c;}p[N];

bool cmp(pp x,pp y){
    return x.c==y.c?(x.s<y.s):(x.c<y.c);
}

int main(){
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++) scanf("%d%d",&p[i].s,&p[i].a);
    for(int i=1;i<=n;i++) p[i].c=max(p[i].s,p[i].a);
    sort(p+1,p+n+1,cmp);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(p[i].s>=d){
            ans++;
            d=max(d,p[i].a);
        }
    }
    printf("%d\n",ans);
    return 0;
}