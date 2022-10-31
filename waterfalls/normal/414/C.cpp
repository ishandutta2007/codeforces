#include <cstdio>
#include <algorithm>

using namespace std;

int n,m;
long long inver;
int a[1048576];
int to[1048576];
long long counts[21];
long long done[21];
long long pairs[21];

void mSort(int L, int R) {
    if (L+1==R) return;
    mSort(L,(L+R)/2);
    mSort((L+R)/2,R);
    int left = L;
    int right = (L+R)/2;
    int num = 0;
    long long cur = 0;
    while (left<(L+R)/2 || right<R) {
        if ((left<(L+R)/2 && a[left]<=a[right]) || (right==R)) {
            to[L+num] = a[left];
            left+=1;
        } else {
            to[L+num] = a[right];
            right+=1;
            cur+=(L+R)/2-left;
        }
        num+=1;
    }
    int which = 0;
    for (which=0;which<=n;which++) if ((1<<which)==R-L) break;
    for (int i=L;i<R;i++) a[i] = to[i];
    int prev = -2147483647;
    int streak = 1;
    for (int i=L;i<=R;i++) {
        if (a[i]==prev && i!=R) streak+=1;
        else {
            pairs[which]-=(long long) streak*(streak-1)/2;
            streak = 1;
            prev = a[i];
        }
    }
    counts[which]+=cur;
    inver+=cur;
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<(1<<n);i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) pairs[i] = (((long long) 1)<<(n-i))*(1<<i)*((1<<i)-1)/2;
    inver = 0;
    mSort(0,1<<n);
    for (int i=n;i>=1;i--) pairs[i]-=pairs[i-1];
    scanf("%d",&m);
    for (int i=0;i<m;i++) {
        int q;
        scanf("%d",&q);
        for (int i=1;i<=q;i++) {
            inver+=pairs[i]-2*counts[i];
            counts[i] = pairs[i]-counts[i];
        }
        printf("%I64d\n",inver);
    }

    return 0;
}