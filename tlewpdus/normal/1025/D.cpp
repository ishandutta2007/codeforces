#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int gcd(int a, int b) {
    if (!a) return b;
    return gcd(b%a,a);
}

int n;
int arr[710];
bool chk[710][710];
vector<int> lis[710], ris[710];
bool D[710][710];

int main() {
    int i, j, k;

    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d",&arr[i]);
    for (i=0;i<n;i++) {
        for (j=i+1;j<n;j++) {
            if (gcd(arr[i],arr[j])>1) {
                chk[i][j] = chk[j][i] = 1;
                lis[i].push_back(j);
                ris[j].push_back(i);
            }
        }
    }
    for (i=0;i<n;i++) reverse(ris[i].begin(),ris[i].end());
    for (i=0;i<n;i++) D[i][i] = 1;
    for (j=1;j<n;j++) {
        for (i=0;i+j<n;i++) {
            for (k=0;k<lis[i].size()&&lis[i][k]<=i+j;k++) D[i][i+j] = D[i][i+j]||(D[lis[i][k]][i+1]&&D[lis[i][k]][i+j]);
        }
        for (i=j;i<n;i++) {
            for (k=0;k<ris[i].size()&&ris[i][k]>=i-j;k++) D[i][i-j] = D[i][i-j]||(D[ris[i][k]][i-1]&&D[ris[i][k]][i-j]);
        }
    }
    bool flag = false;
    for (i=0;i<n;i++) flag = flag||(D[i][0]&&D[i][n-1]);
    puts(flag?"Yes":"No");

    return 0;
}