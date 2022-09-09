#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
int tree[530000];
const int key = 262144;
pii arr[200100];
vector<int> com;
set<int> se;

void upd(int idx) {
    idx += key;
    tree[idx] = 1;
    idx/=2;
    while(idx) {
        tree[idx] = tree[idx*2]+tree[idx*2+1];
        idx/=2;
    }
}

int getv(int s, int e) {
    s+=key; e+=key;
    int ans = 0;
    while(s<=e) {
        if (s&1) ans += tree[s++];
        if (~e&1) ans += tree[e--];
        s/=2;e/=2;
    }
    return ans;
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d%d",&arr[i].x,&arr[i].y);
        com.push_back(arr[i].x);
    }
    sort(com.begin(),com.end());
    com.erase(unique(com.begin(),com.end()),com.end());
    for (int i=0;i<n;i++) arr[i].x = lower_bound(com.begin(),com.end(),arr[i].x)-com.begin();
    sort(arr,arr+n,[](pii a, pii b) {return a.y>b.y||
         (a.y==b.y&&a.x<b.x);});
    int p = 0;
    ll ans = 0;
    for (int i=0;i<n;i++) {
        if (i!=n-1&&arr[i].y==arr[i+1].y) continue;
        for (int j=p;j<=i;j++) se.insert(arr[j].x);
        int s = se.size();
        ans += 1LL*s*(s+1)/2;
        for (int j=p;j<=i;j++) {
            int px = (j==p?0:arr[j-1].x+1);
            int v = getv(px,arr[j].x-1);
            ans -= 1LL*v*(v+1)/2;
            upd(arr[j].x);
        }
        int v = getv(arr[i].x+1,(int)com.size()-1);
        ans -= 1LL*v*(v+1)/2;
        p = i+1;
    }
    printf("%lld\n",ans);

    return 0;
}