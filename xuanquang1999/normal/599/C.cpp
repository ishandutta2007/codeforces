//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define fordit(rit, type, var) for(type::reverse_iterator rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005

//template<class T>
//T min(T a, T b, T c) {
//    return min(a, min(b, c));
//}
//T max(T a, T b, T c) {
//    return max(a, max(b, c));
//}

int n, a[maxN], ans;
mapii rm, before;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        scanf("%d", &a[i]);
        rm[a[i]] = i;
    }

    forit(it, mapii, rm) {
        if (it != rm.begin()) {
            before[it->ff] = (*(--it)).ff;
            ++it;
        }
    }
    forit(it, mapii, rm) {
        int x = it->ff;
        rm[x] = max(rm[x], rm[before[x]]);
    }
    fordit(rit, mapii, rm) {
        int x = rit->ff;
        rm[x] = rm[before[x]];
    }
//    forit(it, mapii, before) {
//        printf("%d %d\n", it->ff, it->ss);
//    }
//    forit(it, mapii, rm) {
//        printf("%d %d\n", it->ff, it->ss);
//    }
    int i = 1, j = 0;
    while (i <= n) {
        int maxRM = max(i, rm[a[i]]);
//        debug(maxRM);
        //debug(rm[before[a[i]]]);
        queue<int> q;
        q.push(a[i]);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            while(j < maxRM) {
//                debug(j);
                if (a[j+1] > u) {
//                    debug(j);
                    maxRM = max(maxRM, rm[a[j+1]]);
                    q.push(a[j+1]);
                }
                ++j;
            }
        }
        ++ans;
        i = j+1;
//        debug(i);
    }

    cout << ans;


    return 0;
}