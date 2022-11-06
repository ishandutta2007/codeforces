#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int q, u, v;
    scanf("%d",&q);
    while(q--) {
        scanf("%d%d",&u,&v);
        if (u > v) {
            puts("NO");
            continue;
        }
        vector<int>b1,b2,p1,p2;
        int hi1 = 0, hi2 = 0;
        int cnt1 = 0, cnt2 = 0;
        for (int i=0;i<30;i++) {
            b1.push_back(u%2);
            b2.push_back(v%2);
            if (u%2) {
                hi1 = max(hi1, i);
                p1.push_back(i);
            }
            if (v%2) {
                hi2 = max(hi2, i);
                p2.push_back(i);
            }
            cnt1 += u%2;
            cnt2 += v%2;
            u/=2;
            v/=2;
        }
        bool ok = true;
        if (cnt1 < cnt2) ok = false;
        else {
            while(!p1.empty() && !p2.empty() && p1.back() == p2.back()) {
                cnt1--;
                cnt2--;
                p1.pop_back();
                p2.pop_back();
            }
            if (cnt2&&p1[cnt1-1]>p2[cnt2-1])ok=false;
            for (int i=0;i<cnt2-1;i++) {
                if (p1[i]>p2[i]) ok=false;
            }
        }
        puts(ok ? "YES" : "NO");
    }
}