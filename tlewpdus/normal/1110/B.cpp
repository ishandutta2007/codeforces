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

int n, m, k;
int arr[100100];
vector<int> vec;

int main() {
    int i;

    scanf("%d%d%d",&n,&m,&k);
    for (i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        if (i) vec.push_back(arr[i]-arr[i-1]-1);
    }
    sort(vec.begin(),vec.end());
    int s = n;
    for (i=0;i<n-k;i++) s+=vec[i];
    printf("%d\n",s);

    return 0;
}