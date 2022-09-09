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
pii arr[300100];
int ord[300100];

int main() {
    int i;

    scanf("%d",&n);
    int inc = 0;
    for (i=0;i<n;i++) {
        scanf("%d%d",&arr[i].x,&arr[i].y);
        if (arr[i].x<arr[i].y) inc++;
        ord[i] = i;
    }
    printf("%d\n",max(inc,n-inc));
    if (inc<n-inc) {
        sort(ord,ord+n,[](int a, int b) {
                return arr[a].y<arr[b].y;
             });
        for (i=0;i<n;i++) {
            if (arr[ord[i]].x>arr[ord[i]].y) {
                printf("%d ",ord[i]+1);
            }
        }
        printf("\n");
    }
    else {
        sort(ord,ord+n,[](int a, int b) {
                return arr[a].y>arr[b].y;
             });
        for (i=0;i<n;i++) {
            if (arr[ord[i]].x<arr[ord[i]].y) {
                printf("%d ",ord[i]+1);
            }
        }
        printf("\n");
    }


    return 0;
}