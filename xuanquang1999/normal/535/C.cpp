using namespace std;
#include <bits/stdc++.h>
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define ll long long
#define maxN 2000005
ll A, B, t, m, kar[maxN], skar[maxN];
int n, l;

bool check(int r) {
//    if (r-l+1 <= m) return (kar[r] <= t);
//    else return (skar[r]-skar[l-1] <= m*t);
    return (kar[r] <= t && skar[r]-skar[l-1] <= m*t);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%I64d%I64d%d", &A, &B, &n);
    fto(i, 1, maxN-1) {
        kar[i] = min((ll)1000001, A+(i-1)*B);
        //kar[i] = A+(i-1)*B;
        skar[i] = skar[i-1]+kar[i];
        //printf("%I64d %I64d\n", kar[i], skar[i]);
    }

    fto(i, 1, n) {
        scanf("%d%I64d%I64d", &l, &t, &m);
        int sl = l, sr = maxN-1, res = -1;
        while (sl <= sr) {
            int mid = (sl+sr)/2;
            if (check(mid)) {
                if (mid > res) res = mid;
                sl = mid+1;
            }
            else sr = mid-1;
        }

        printf("%d\n", res);
    }
}