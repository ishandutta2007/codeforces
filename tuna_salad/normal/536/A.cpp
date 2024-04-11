// Testing on ping128's A
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define INF (0x3f3f3f3f)

#define SZ(x) ((int)((x).size()))
#define PB(x) push_back(x)
#define MEMSET(x,v) memset(x,v,sizeof(x))
#define REP(i,n) for(int (i)=0;(i)<(n);++(i))

typedef long long LL;
typedef pair<int, int> PII; typedef pair<PII, int> PII2;

LL h(LL A, LL B, LL x) {
    return A + (x - 1) * B;
}

bool good(LL A, LL B, LL l, LL r, LL t, LL m) {
    LL sl = h(A,B,l);
    LL sr = h(A,B,r);
    LL num = (r - l + 1);

    
    if (m == 1) {
        return (sl + sr) * num / 2 <= t;
    } else {
        LL sum = (sl + sr) * num / 2;
        LL x = (sum + m - 1) / m;
        return max(x, sr) <= t;
    }
    /*
        
        LL n_group = num / (2 * m);
        LL a1 = h(A,B,r) + h(A,B,r - 2 * m + 1);
        LL a2 = h(A,B,r - 2 * m) + h(A,B,r - 4 * m + 1);
        LL diff = a1 - a2;
        LL need = 0;
        //        if (r == 4)
        //            cout << n_group << endl;
        if (n_group == 1) {
            need += a1;
        } else if (n_group > 1) {
            LL ff = a1 - (n_group - 1) * diff;
            need += (ff + a1) * n_group / 2;
        }
        num %= 2 * m;
        if (num) {
            LL last = h(A, B, l + num - 1);
            if (num <= m) need += last;
            else need += max(last, h(A, B, l + num - 1 - m + 1) + h(A, B, l + num - 1 - m));
        }
        return need <= t;
    }
    */
}

int main() {
    int n;
    LL A, B;
    cin >> A >> B >> n;
    LL l, t, m;
    REP(tt, n) {
        cin >> l >> t >> m;
        LL left = l, right = max(l, 1000000LL);
        while (left <= right) {
            LL mid = (left + right) / 2;
            if (good(A, B, l, mid, t, m)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (right == l - 1) {
            printf("-1\n");
        } else {
            cout << right << endl;
        }
    }
    
    return 0;
}