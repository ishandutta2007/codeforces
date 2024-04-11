#include <bits/stdc++.h>
using namespace std;
#define ll long long
pair<int,int> seg[1000005];
vector<pair<int,int>> queries[500001];
map<int,int> last;
int n;
void build(){
    for(int i=n-1;i>=1;i--) seg[i] = min(seg[2*i],seg[2*i+1]);
}
void upd(int i,int x){
    seg[i+=n].first = x;
    while(i>1){
        i/=2;
        seg[i]= min(seg[2*i],seg[2*i+1]);
    }
}
pair<int,int> query(int l,int r){
    l+=n; r+=n;
    pair<int,int> res = {1000000000,1000000000};
    while(l<r){
        if(l%2) res = min(res,seg[l++]);
        if(r%2) res = min(res,seg[--r]);
        l/=2; r/=2;
    }
    return res;
}
int ans[500001];
int main(){
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int q; scanf("%d",&q);
    for(int i=0;i<q;i++){
        int a,b; scanf("%d%d",&a,&b);
        --a; --b;
        queries[b].push_back({a,i});
    }
    build();
    for(int i=n;i<2*n;i++)
        seg[i] = {-1,a[i-n]};
    for(int i=0;i<n;i++) last[a[i]] = -1;
    build();
    for(int i=0;i<n;i++){
        if(last[a[i]]!=-1){
            upd(i,last[a[i]]);
            upd(last[a[i]],1000000);
        }
        last[a[i]] = i;
        for(auto q : queries[i]){
            pair<int,int> temp = query(q.first,i+1);
            if(temp.first>=q.first){
                ans[q.second] = 0;
            }
            else{
                ans[q.second] = temp.second;
            }
        }
    }
    for(int i=0;i<q;i++){
        printf("%d\n",ans[i]);
    }
    
}