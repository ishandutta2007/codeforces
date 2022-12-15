#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int st[3*MN], n, q, i, x, y, arr[MN];
set<int> pos[MN]; map<int,int> mp, p;
void build(int i,int s,int e){
    if(s != e){
        build(2*i,s,(s+e)/2); build(2*i+1,(s+e)/2+1,e);
        st[i] = __gcd(st[2*i], st[2*i+1]);
    }
    else st[i] = arr[s];
}
int qu(int i,int s,int e,int ss,int se){
    if(s >= ss&&e <= se) return st[i];
    else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
    else return __gcd(qu(2*i,s,(s+e)/2,ss,se),qu(2*i+1,(s+e)/2+1,e,ss,se));
}
int main(){
    for(scanf("%d",&n),i=1;i<=n;i++)
        scanf("%d",&arr[i]), mp[arr[i]]=0;
    build(1,1,n);
    i=0; auto it = mp.begin();
    for(;it!=mp.end();it++) it->second = ++i;
    for(i=1;i<=n;i++){
        int t = mp[arr[i]];
        pos[t].insert(i);
        p[i] = pos[t].size();
    }
    for(scanf("%d",&q);q;q--){
        scanf("%d%d",&x,&y);
        int g = qu(1,1,n,x,y);
        if(!mp.count(g)) printf("%d\n",y-x+1);
        else{
            int t = mp[g], a=pos[t].size()+1, b=0;
            auto it = pos[t].lower_bound(x);
            if(it != pos[t].end()) a=p[*it];
            it = pos[t].upper_bound(y);
            if(it != pos[t].begin()) it--, b=p[*it];
            printf("%d\n",y-x+1-(b-a+1));
        }
    }
    return 0;
}