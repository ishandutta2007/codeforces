#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
int seg[2000000];
int sz = 1;
int n,m,q;
void init(){
    while(sz<m) sz*=2;
}
void upd(int i){
    seg[i+=sz]++;
    while(i>1){
        i/=2; 
        seg[i] = seg[2*i]+seg[2*i+1];
    }
    return;
}
int kthone(int num){
    int curr=1;
    while(curr<sz){
        curr*=2;
        if(seg[curr]<num){
            num-=seg[curr];
            curr++;
        }
    }
    return curr-sz; //check this indexing
}
int num[500005];
ll daysUntil[500005];
vector<int> freq[500005];
vector<pair<ll,int>> queries;
int ans[500005];
int main(){
    scanf("%d%d%d",&n,&m,&q);
    init();
    for(int i=0;i<n;i++){
        int x; scanf("%d",&x);
        ++num[x];
    }
    for(int i=1;i<=m;i++) freq[num[i]].push_back(i);
    ll curr = n ;
    ll num = 0;
    for(int i=0;i<q;i++){
        ll k; scanf("%lld",&k);
        queries.push_back({k,i});
    }
    sort(queries.begin(),queries.end());
    auto it = queries.begin();
    int idx = 1;
    while(it!=queries.end()){
        if(idx>500002) break;
        else{
            num+=freq[idx-1].size();
            curr+=num;
            for(auto &next : freq[idx-1]){
                //cout << next << endl;
                upd(next-1);
            }
            while(it!=queries.end() && curr>=(*it).first){
                //do a query
                curr-=num;
                ll need = (((*it).first-curr)%num+num)%num;
                if(need==0) need = num;
                ans[(*it).second] = kthone(need);
                curr+=num;
                ++it;
            }
            ++idx;
        }
    }
    while(it!=queries.end()){
        //answer larger query
        ll need = (((*it).first-curr)%num+num)%num;
        if(need==0) need=num;
        ans[(*it).second] = kthone(need);
        ++it;
    }
    for(int i=0;i<q;i++) printf("%d\n",ans[i]+1);
}