#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
pair<int,int> store[1000001];
int main() {
    int n,x;
    cin >> n >> x;
    int a[n];
    for(int i=0;i<=1000000;i++) store[i] = {1000001+i,-1};
    for(int i=0;i<n;i++) {
        cin >> a[i];
        store[a[i]].f = min(store[a[i]].f,i+1);
        store[a[i]].s = max(store[a[i]].s,i+1);
    }
    multiset<int> right;
    int l = 2000001;
    map<int,int> f;
    for(int i=x;i>=1;i--) {
        if(store[i].s<l) {
            right.insert(store[i].f);
            f[store[i].f] = i;
            l = min(l,store[i].f);
        }
        else break;
    }
    int r = -1;
    long long ans = 0;
    for(int i=1;i<=x;i++) {
        //l = (i+1)
        if(store[i-1].f>r) {
            r = max(r,store[i-1].s);
        }
        else break;
        auto it = right.lower_bound(r);
        if(it==right.begin())  {
            ans+=min((int)right.size()+1,x-i+1);
            continue;
        }
        else --it;
        int num = f[(*it)];
        ans+=min(x-num+1,x-i+1);
    }
    cout << ans << endl;
}