#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n;
int ran[5010][5010];
int arr[5010];

int main() {
    int i;

    scanf("%d",&n);
    for (i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        ran[i][i] = arr[i];
    }
    for (int l=1;l<n;l++) {
        for (i=0;i+l<n;i++) {
            ran[i][i+l]=ran[i][i+l-1]^ran[i+1][i+l];
        }
    }
    for (int l=1;l<n;l++) {
        for (i=0;i+l<n;i++) {
            ran[i][i+l]=max(max(ran[i][i+l-1],ran[i+1][i+l]),ran[i][i+l]);
        }
    }
    int a, b;
    int q;
    scanf("%d",&q);
    for (i=0;i<q;i++) {
    scanf("%d%d",&a,&b); a--; b--;
    printf("%d\n",ran[a][b]);}

    return 0;
}