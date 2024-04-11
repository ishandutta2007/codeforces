#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
vector<int> pos[MN];
int st[3*MN], N, i, arr[MN];
vector<pair<int,int>> sol;
void upd(int i,int s,int e,int ind){
    if(s != e){
        if((s+e)/2<ind) upd(2*i+1,(s+e)/2+1,e,ind);
        else upd(2*i,s,(s+e)/2,ind);
        st[i] = min(st[2*i], st[2*i+1]);
    }
    else st[i] = arr[s];
}
int qu(int i,int s,int e,int ss,int se){
    if(s>=ss&&e<=se) return st[i];
    else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
    else return min(qu(2*i+1,(s+e)/2+1,e,ss,se),qu(2*i,s,(s+e)/2,ss,se));
}
void solve(int l,int r,int h){
    if(l>r) return;
    int a = qu(1,1,N,l,r);
    for(h++;h<=a;h++) sol.push_back({l,r});
    int p = lower_bound(pos[a].begin(),pos[a].end(),l)-pos[a].begin();
    int last = l-1, idk = 0;
    for(;p<pos[a].size()&&pos[a][p]<=r;p++){
        if(pos[a][p]==r) idk=1;
        solve(last+1, pos[a][p]-1, a);
        last = pos[a][p];
    }
    if(!idk) solve(last+1, r, a);
}
int main(){
    for(scanf("%d",&N),i=1;i<=N;i++){
        scanf("%d",&arr[i]);
        upd(1, 1, N, i);
        pos[arr[i]].push_back(i);
    }
    solve(1, N, 0);
    printf("%d\n",sol.size());
    for(auto v : sol) printf("%d %d\n",v.first,v.second);
    return 0;
}