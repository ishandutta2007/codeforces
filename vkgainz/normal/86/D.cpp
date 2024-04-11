#include <bits/stdc++.h>
using namespace std;
#define ll long long
int block_sz;
struct query{
    int l,r,i;
};
bool cmp(const query &x, const query &y){
    if(x.l/block_sz==y.l/block_sz)
        return x.r<y.r;
    return x.l/block_sz<y.l/block_sz;
}
ll curr;
int freq[1000001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int t; cin >> t;
    block_sz = sqrt(n);
    int a[n];
    ll ans[t];
    for(int i=0;i<n;i++)
        cin >> a[i];
    query queries[t];
    for(int i=0;i<t;i++){
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--; queries[i].r--;
        queries[i].i = i;
    }
    sort(queries,queries+t,cmp);
    int currL = 0;
    int currR = -1;
    for(int i=0;i<t;i++){
        while(currR<queries[i].r){
            currR++;
            freq[a[currR]]++;
            curr+=(2*freq[a[currR]]-1)*1LL*a[currR];
        }
        while(currR>queries[i].r){
            curr-=(2*freq[a[currR]]-1)*1LL*a[currR];
            freq[a[currR]]--;
            currR--;
        }
        while(currL<queries[i].l){
            curr-=(2*freq[a[currL]]-1)*1LL*a[currL];
            freq[a[currL]]--;
            currL++;
        }
        while(currL>queries[i].l){
            currL--;
            freq[a[currL]]++;
            curr+=(2*freq[a[currL]]-1)*1LL*a[currL];
        }
        ans[queries[i].i] = curr;
    }
    for(int i=0;i<t;i++)
        cout << ans[i] << endl;
}