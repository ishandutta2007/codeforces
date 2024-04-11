#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int n;
int arr[1100];
int x[1100];

int main() {
    int i;

    scanf("%d",&n);
    for (i=1;i<n+1;i++)scanf("%d",&arr[i]);
    for (i=0;i<n;i++) {
        x[i] = arr[i+1]-arr[i];
    }
    int j;
    vector<int> vec;
    for (i=1;i<=n;i++) {
        bool fl = 1;
        for (j=i;j<n;j++) {
            if (x[j]!=x[j-i]) fl = 0;
        }
        if (fl) vec.push_back(i);
    }
    printf("%d\n",vec.size());
    for (int &v :vec)printf("%d ",v);
    printf("\n");

    return 0;
}