#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300050;
const int M=2*N;
const ll inf=4e18+5;
int n,q,x[N],w[N];
int ls[M],rs[M],root,tsz;
ll st[M],ans[N];
vector<int> E[N];
vector<pair<int,int>> Qs[N];
void Build(int&c,int ss,int se){
c=++tsz;st[c]=inf;
if(ss==se)return;
int mid=ss+se>>1;
Build(ls[c],ss,mid);
Build(rs[c],mid+1,se);
}
void Set(int c,int ss,int se,int qi,ll v){
st[c]=min(st[c],v);
if(ss==se)return;
int mid=ss+se>>1;
if(qi<=mid)Set(ls[c],ss,mid,qi,v);
else Set(rs[c],mid+1,se,qi,v);
}
ll Get(int c,int ss,int se,int qs,int qe){
if(ss>se||ss>qe||se<qs)return inf;
if(qs<=ss&&se<=qe)return st[c];
int mid=ss+se>>1;
return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int main(){
scanf("%i%i",&n,&q);
for(int i=1;i<=n;i++)scanf("%i%i",&x[i],&w[i]);
stack<int> stk;
for(int i=1;i<=n;i++){
while(!stk.empty()&&w[stk.top()]>w[i])stk.pop();
if(!stk.empty())E[i].push_back(stk.top());
stk.push(i);
}
while(!stk.empty())stk.pop();
for(int i=n;i>=1;i--){
while(!stk.empty()&&w[i]<w[stk.top()])stk.pop();
if(!stk.empty())E[stk.top()].push_back(i);
stk.push(i);
}
Build(root,1,n);
for(int i=1;i<=q;i++){
int l,r;
scanf("%i%i",&l,&r);
Qs[r].push_back({l,i});
}
for(int i=1;i<=n;i++){
for(int j:E[i])Set(root,1,n,j,(ll)(x[i]-x[j])*(ll)(w[i]+w[j]));
for(auto qs:Qs[i])ans[qs.second]=Get(root,1,n,qs.first,i);
}
for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
return 0;
}