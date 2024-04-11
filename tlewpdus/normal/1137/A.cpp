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

int n, m;
int arr[1010][1010];
int trr[4][1010][1010];

int main() {
    int i, j;

    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) scanf("%d",&arr[i][j]);
    }
    for (i=0;i<n;i++) {
        vector<int> vec;
        for (j=0;j<m;j++) vec.push_back(arr[i][j]);
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        for (j=0;j<m;j++) {
            trr[0][i][j] = lower_bound(vec.begin(),vec.end(),arr[i][j])-vec.begin()+1;
            trr[1][i][j] = vec.size()-trr[0][i][j];
        }
    }
    for (j=0;j<m;j++) {
        vector<int> vec;
        for (i=0;i<n;i++) vec.push_back(arr[i][j]);
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        for (i=0;i<n;i++) {
            trr[2][i][j] = lower_bound(vec.begin(),vec.end(),arr[i][j])-vec.begin()+1;
            trr[3][i][j] = vec.size()-trr[2][i][j];
        }
    }
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            printf("%d ",max(trr[0][i][j],trr[2][i][j])+
                                 max(trr[1][i][j],trr[3][i][j]));
        }
        printf("\n");
    }

    return 0;
}