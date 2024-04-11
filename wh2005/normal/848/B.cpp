#include<bits/stdc++.h>
using namespace std;
#define pi pair<int ,int >
#define mcp(x,y) make_pair(x,y)
const int N = 1e5+9;
int n,w,h;
struct pp{int op,p,t,id,val;}p[N];
bool cmp(pp x,pp y){
    return x.val==y.val?(x.op==y.op?(x.p<y.p):(x.op<y.op)):(x.val<y.val);
}
deque<int >q;
pi ans[N];

int main(){
    scanf("%d%d%d",&n,&w,&h);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&p[i].op,&p[i].p,&p[i].t);p[i].id=i,p[i].val=p[i].p-p[i].t;
        if(p[i].op==2) p[i].op=1;
        else p[i].op=2;
    }
    sort(p+1,p+n+1,cmp);
    for(int l=1,r=1;l<=n;l=r+1){
        int mid=(p[l].op==1?l:l-1);r=l;
        while(r<n&&p[r+1].val==p[l].val){r++;if(p[r].op==1) mid=r;}
        if(mid==l-1||mid==r) continue;
        q.clear();
        for(int i=mid+1;i<=r;i++) q.push_back(p[i].id);
        for(int i=l;i<=mid;i++){
            q.push_front(p[i].id);p[i].id=q[q.size()-1];q.pop_back();
        }
        for(int i=mid+1;i<=r;i++){int ps=i-mid-1;p[i].id=q[ps];}
    }
    for(int i=1;i<=n;i++){
        if(p[i].op==1) ans[p[i].id]=mcp(w,p[i].p);
        else ans[p[i].id]=mcp(p[i].p,h);
    }
    for(int i=1;i<=n;i++) printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}