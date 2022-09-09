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
int arr[400100];

int main() {
    int t;

    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d",&arr[i]);
        if (n==1) {
            puts("0 0 0");
            continue;
        }
        int p = 0;
        vector<int>vec;
        int asum = 0;
        for (int i=0;i<n/2;i++) {
            if (arr[i]!=arr[i+1]) {
                vec.push_back(i-p+1);
                asum += i-p+1;
                p=i+1;
            }
        }
        if (vec.size()<3) {
            puts("0 0 0");
            continue;
        }
        int s = 1, sum = 0;
        for (;s<vec.size();s++) {
            sum+=vec[s];
            if (sum>vec[0]) break;
        }
        if (s==vec.size()) {

            puts("0 0 0");
            continue;
        }
        int e = (int)vec.size()-1; sum = 0;
        for (;e>0;e--) {
            sum+=vec[e];
            if (sum>vec[0]) break;
        }
        if (e==0||e<=s) {
            puts("0 0 0");
            continue;
        }
        printf("%d %d %d\n",vec[0],asum-vec[0]-sum,sum);
    }

	return 0;
}