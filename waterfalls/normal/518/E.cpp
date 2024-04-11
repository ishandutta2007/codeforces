#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int k,n,ok;
char number[20];
int a[100013];

void solve(int l, int r) {
    int first = (l<0 ? -1010000007 : a[l]);
    int last = (r>=n ? 1010000007 : a[r]);
    int num = (r-l)/k-1;
    if (last-first-1<num) ok = 0;
    if (first<0 && last>0) {
        int one = min(max(first+1,-num/2),last-num);
        for (int i=l+k;i<r;i+=k) a[i] = one+(i-l)/k-1;
    } else {
        if (first>=0) for (int i=l+k;i<r;i+=k) a[i] = first+(i-l)/k;
        else for (int i=r-k;i>l;i-=k) a[i] = last-(r-i)/k;
    }
}

int main() {
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) {
        scanf(" %s",&number);
        if (number[0]=='?') a[i] = 1000000007;
        else sscanf(number,"%d",&a[i]);
    }
    ok = 1;
    for (int i=0;i<k;i++) {
        int prev = i-k;
        for (int j=i;j<n;j+=k) {
            if (a[j]!=1000000007) {
                if (prev>=0 && a[j]<=a[prev]) ok = 0;
                if (prev!=j-k) solve(prev,j);
                prev = j;
            }
        }
        if (prev!=i+(n-1-i)/k*k) solve(prev,i+(n-1-i)/k*k+k);
    }
    if (ok) {
        for (int i=0;i<n;i++) printf("%d ",a[i]);
        printf("\n");
    } else printf("Incorrect sequence\n");

    return 0;
}