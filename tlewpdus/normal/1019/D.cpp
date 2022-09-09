#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll ccw(pll a, pll b, pll c) {
    return a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x;
}

pll operator - (pll &a, pll &b) {
    return pll(a.x-b.x,a.y-b.y);
}

int n;
ll S;
pll arr[2100];
int ord[2100];
int loc[2100];
vector<pii> lis;

void print (int a, int b, int c) {
    printf("Yes\n");
    printf("%lld %lld\n%lld %lld\n%lld %lld\n",arr[a].x,arr[a].y,arr[b].x,arr[b].y,arr[c].x,arr[c].y);
    exit(0);
}

int main() {
    int i, j;

    scanf("%d%lld",&n,&S);
    for (i=0;i<n;i++) scanf("%lld%lld",&arr[i].x,&arr[i].y);
    sort(arr,arr+n);

    for (i=0;i<n;i++) {
        ord[i] = loc[i] = i;
        for (j=i+1;j<n;j++) lis.push_back(pii(i,j));
    }
    sort(lis.begin(),lis.end(),[](pii a, pii b) {
            if (ccw(pll(0,0),arr[a.y]-arr[a.x],arr[b.y]-arr[b.x])!=0) return ccw(pll(0,0),arr[a.y]-arr[a.x],arr[b.y]-arr[b.x])>0;
            return a<b;
         });
    for (i=0;i<lis.size();i++) {
        int a = lis[i].x, b = lis[i].y;
        if (abs(loc[a]-loc[b])!=1) {
            while(true);
            return 0;
        }
        int s = max(loc[a],loc[b])+1, e = n-1;
        while(s<=e) {
            int m = (s+e)/2;
            ll v = abs(ccw(arr[a],arr[b],arr[ord[m]]));
            if (v==2*S) print(a,b,ord[m]);
            if (v>2*S) e = m-1;
            else s = m+1;
        }
        s = 0, e = min(loc[a],loc[b])-1;
        while(s<=e) {
            int m = (s+e)/2;
            ll v = abs(ccw(arr[a],arr[b],arr[ord[m]]));
            if (v==2*S) print(a,b,ord[m]);
            if (v>2*S) s = m+1;
            else e = m-1;
        }
        swap(ord[loc[a]],ord[loc[b]]);
        swap(loc[a],loc[b]);
    }
    printf("No\n");

    return 0;
}