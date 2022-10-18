using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define fordit(rit, type, var) for(type::reverse_iterator rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 1000025
//#define maxN 10

int n, cnt[maxN], ans;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
    }

    fto(iTimes, 1, 20) {
        fto(i, 0, maxN-2) {
            int p2 = 1, k = 0;
            while (cnt[i] >= p2) {
                p2*=2;
                ++k;
            }
            //debug(i);
            //debug(p2);
            cnt[i]-=p2/2;
            if (k > 0) cnt[i+k-1]+=1;
//            fto(i, 0, maxN-1) printf("%d ", cnt[i]);
//            printf("\n");
        }
    }

    fto(i, 0, maxN-1) ans+=cnt[i];

    cout << ans;




    return 0;
}