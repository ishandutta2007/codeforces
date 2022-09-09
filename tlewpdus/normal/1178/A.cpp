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
int arr[110];

int main() {
    scanf("%d",&n);
    int sum = 0;
    for (int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    int tum = arr[0];
    vector<int> vec(1,0);
    for (int i=1;i<n;i++) {
        if (arr[i]*2<=arr[0]) {
            vec.push_back(i);
            tum+=arr[i];
        }
    }
    if (tum*2>sum) {
        printf("%d\n",vec.size());
        for (int &v : vec) printf("%d ",v+1); printf("\n");
    }
    else printf("0\n");

    return 0;
}