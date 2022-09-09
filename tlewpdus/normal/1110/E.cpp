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
int arr[100100], brr[100100];
vector<int> vec, sec;

int main() {
    int i;

    scanf("%d",&n);
    for (i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        if (i) vec.push_back(arr[i]-arr[i-1]);
    }
    for (i=0;i<n;i++) {
        scanf("%d",&brr[i]);
        if (i) sec.push_back(brr[i]-brr[i-1]);
    }
    sort(vec.begin(),vec.end());
    sort(sec.begin(),sec.end());
    for (i=0;i<n-1;i++) if (vec[i]!=sec[i]) {
        puts("No");
        return 0;
    }
    puts((arr[0]==brr[0]&&arr[n-1]==brr[n-1])?"Yes":"No");

    return 0;
}