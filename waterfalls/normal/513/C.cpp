#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int L[5];
int R[5];

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d%d",&L[i],&R[i]);
    double ways = 0;
    for (int i=1;i<(1<<n);i++) {
        int bits = 0;
        for (int j=0;j<n;j++) if (i&(1<<j)) bits+=1;
        if (bits==1) {
            for (int j=0;j<n;j++) if (i&(1<<j)) bits = j;
            for (int other=0;other<n;other++) {
                if (bits==other) continue;
                for (int j=L[bits];j<=R[bits];j++) {
                    long long add = 1;
                    for (int k=0;k<n;k++) {
                        if (bits==k || other==k) continue;
                        if (j>L[k]) add*=min(j-L[k],R[k]-L[k]+1);
                        else add = 0;
                    }
                    if (R[other]<=j) add = 0;
                    add*=min(R[other]-j,R[other]-L[other]+1);
                    ways+=(double) j*add;
                }
            }
            continue;
        }
        int from = 0;
        for (int j=0;j<n;j++) if (i&(1<<j)) from = max(from,L[j]);
        int to = 100000;
        for (int j=0;j<n;j++) if (i&(1<<j)) to = min(to,R[j]);
        for (int j=from;j<=to;j++) {
            long long add = 1;
            for (int k=0;k<n;k++) {
                if (i&(1<<k)) continue;
                if (j>L[k]) add*=min(j-L[k],R[k]-L[k]+1);
                else add = 0;
            }
            ways+=(double) j*add;
        }
        for (int other=0;other<n;other++) {
            if (i&(1<<other)) continue;
            for (int j=from;j<=to;j++) {
                long long add = 1;
                for (int k=0;k<n;k++) {
                    if ((i&(1<<k)) || (other==k)) continue;
                    if (j>L[k]) add*=min(j-L[k],R[k]-L[k]+1);
                    else add = 0;
                }
                if (R[other]<=j) add = 0;
                add*=min(R[other]-j,R[other]-L[other]+1);
                ways+=(double) j*add;
            }
        }
    }
    for (int i=0;i<n;i++) ways/=R[i]-L[i]+1;
    printf("%1.12f\n",ways);

    return 0;
}