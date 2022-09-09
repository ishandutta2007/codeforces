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
int arr[51];

int main() {
    int i;

    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d",&arr[i]);
    int j;
    for (j=1;j<=50;j++) {
        int c = 0;
        for (i=0;i<n;i++) {
            if (arr[i]==j) c++;
        }
        if (c>n/2) {
            puts("Bob");
            return 0;
        }
        else if (c>0) {
            puts("Alice");
            return 0;
        }
    }


    return 0;
}