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
char str[100100];

int main() {
    int i;

    scanf("%d",&n);
    scanf("%s",str);
    for (i=0;str[i]=='S';i++);
    int p = i, c = 0;
    vector<int> vec;
    for (;i<n;i++) {
        if (str[i]=='G') c++;
        if (i==n-1||str[i]!=str[i+1]) {
            vec.push_back(i-p+1);
            p = i+1;
        }
    }
    int v = 0;
    for (i=0;i<vec.size();i+=2) v = max(v,vec[i]+1);
    for (i=0;i+2<vec.size();i+=2) {
        if (vec[i+1]==1) v = max(v,vec[i]+vec[i+2]+1);
    }
    printf("%d\n",min(v,c));

    return 0;
}