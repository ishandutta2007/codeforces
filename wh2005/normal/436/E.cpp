#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1e18+7;
const int N = 3e5+9;
int n,m,res[N];ll a[N],b[N];
struct node{ll val;int id;};
priority_queue<node >q1,q2,q3,q4,q5;
bool operator<(const node x,const node y){return x.val>y.val;}
/*

1.x 0->1,res[x]=0,cnt=a[x];
2.x 1->2,res[x]=1,cnt=b[x]-a[x];
3.y 2->1 x 0->2,res[x]=0,res[y]=2,cnt=b[x]-b[y]+a[y]
4.y 1->0 x 0->2,res[x]=0,res[y]=1,cnt=b[x]-a[y]
5x,y
q1:a[x],res[x]==0
q2:b[x]-a[x],res[x]==1
q3:b[x],res[x]==0
q4:-a[x],res[x]==1
q5:-b[x]+a[x],res[x]==2
*/
ll ask1(){
    while(!q1.empty()&&res[q1.top().id]!=0) q1.pop();
    if(q1.empty()) return inf;return q1.top().val;
}
ll ask2(){
    while(!q2.empty()&&res[q2.top().id]!=1) q2.pop();
    if(q2.empty()) return inf;return q2.top().val;
}
ll ask3(){
    while(!q3.empty()&&res[q3.top().id]!=0) q3.pop();
    if(q3.empty()) return inf;
    while(!q5.empty()&&res[q5.top().id]!=2) q5.pop();
    if(q5.empty()) return inf;return q3.top().val+q5.top().val;
}
ll ask4(){
    while(!q3.empty()&&res[q3.top().id]!=0) q3.pop();
    if(q3.empty()) return inf;
    while(!q4.empty()&&res[q4.top().id]!=1) q4.pop();
    if(q4.empty()) return inf;return q3.top().val+q4.top().val;
}
void update0(int x){
    q1.push(node{a[x],x});q3.push(node{b[x],x});return ;
}
void update1(int x){
    q2.push(node{b[x]-a[x],x});q4.push(node{-a[x],x});return ;
}
void update2(int x){
    q5.push(node{-b[x]+a[x],x});return ;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&a[i],&b[i]);
        q1.push(node{a[i],i});q3.push(node{b[i],i});
    }
    memset(res,0,sizeof(res));ll ans=0;
    while(m--){
        ll A=ask1(),B=ask2(),C=ask3(),D=ask4();
        ll Mn=min(min(A,B),min(C,D));ans+=Mn;
        if(Mn==A){
            res[q1.top().id]=1;update1(q1.top().id);q1.pop();
        }
        else if(Mn==B){
            res[q2.top().id]=2;update2(q2.top().id);q2.pop();
        }
        else if(Mn==C){
            res[q3.top().id]=2;update2(q3.top().id);q3.pop();
            res[q5.top().id]=1;update1(q5.top().id);q5.pop();
        }
        else if(Mn==D){
            res[q3.top().id]=2;update2(q3.top().id);q3.pop();
            res[q4.top().id]=0;update0(q4.top().id);q4.pop();
        }
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++) printf("%d",res[i]);puts("");
    return 0;
}