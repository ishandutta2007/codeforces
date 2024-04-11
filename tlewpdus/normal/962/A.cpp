#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n;
int arr[200100];

int main() {
    int i;

    scanf("%d",&n);
    int s = 0;
    for (i=0;i<n;i++) {
        scanf("%d",&arr[i]); s+=arr[i];
    }
    int t = 0;
    for (i=0;i<n;i++) {
        t += arr[i];
        if (t>=(s+1)/2) {
            printf("%d\n",i+1);
            return 0;
        }
    }

    return 0;
}