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
int arr[100100];

void print(int t) {
    puts(t?"cslnb":"sjfnb");
    exit(0);
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&arr[i]);
    sort(arr,arr+n);
    int c = 0;
    for (int i=1;i<n;i++) {
        c += (int)(arr[i]==arr[i-1]);
    }
    if (c>1) {
        print(1);
    }
    int t = 0;
    if (c==1) {
        for (int i=1;i<n;i++) {
            if (arr[i]==arr[i-1]) {
                if (arr[i]==0) print(1);
                arr[i-1]--;
                break;
            }
        }
        for (int i=1;i<n;i++) {
            if (arr[i]==arr[i-1]) print(1);
        }
        t = 1;
    }
    ll sum = 0;
    for (int i=0;i<n;i++) sum += arr[i];
    sum -= 1LL*n*(n-1)/2;
    print(((sum%2)^t)^1);

    return 0;
}