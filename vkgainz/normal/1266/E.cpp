#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<pair<int,int>,int> m;
map<int,int> freq;
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    ll sum = 0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    int q; scanf("%d",&q);
    while(q--){
        int s,t,u;
        scanf("%d%d%d",&s,&t,&u);
        if(m[make_pair(s,t)]){
            int uCurr = m[make_pair(s,t)];
            --freq[uCurr];
            if(freq[uCurr]<a[uCurr-1]){
                ++sum;
            }
            m[make_pair(s,t)] = 0;
        }
        if(u!=0){
            ++freq[u];
            if(freq[u]<=a[u-1]){
                --sum;
            }
            m[make_pair(s,t)] = u;
        }
        printf("%lld\n",sum);
    }
}