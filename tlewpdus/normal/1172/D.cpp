#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> piii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
int arr[1010], brr[1010], trr[1010];
int cura[1010], curb[1010];
int main() {
    int i, j;

    scanf("%d",&n);
    for (i=0;i<n;i++) {
        scanf("%d",&arr[i]); arr[i]--;
        trr[arr[i]] = i;
        cura[i] = i;
    }
    for (i=0;i<n;i++) arr[i]=trr[i];
    for (i=0;i<n;i++) {
        scanf("%d",&brr[i]); brr[i]--;
        trr[brr[i]] = i;
        curb[i] = i;
    }
    for (i=0;i<n;i++) brr[i]=trr[i];

    vector<piii> ans;
    for (i=0;i<n;i++) {
        if (arr[i]==cura[i]&&brr[i]==curb[i]) continue;
        int p, q;
        for (j=i;j<n;j++) if (cura[j]==arr[i]) break;
        p=j;
        for (j=i;j<n;j++) if (curb[j]==brr[i]) break;
        q=j;
        ans.push_back(piii(pii(p,i),pii(i,q)));
        swap(cura[p],cura[i]);
        swap(curb[q],curb[i]);
    }

    printf("%d\n",ans.size());
    for (piii &v : ans) {
        printf("%d %d %d %d\n",v.x.x+1,v.x.y+1,v.y.x+1,v.y.y+1);
    }

    return 0;
}