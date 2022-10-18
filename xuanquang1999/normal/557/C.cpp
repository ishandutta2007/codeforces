using namespace std;
#include <bits/stdc++.h>
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005
#define maxL 100005
#define maxD 205
int l[maxN], d[maxN], n, cnt[maxD], suf, ans;
vector<int> v[maxL];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d", &l[i]);
    fto(i, 0, n-1) scanf("%d", &d[i]);
    fto(i, 0, n-1) v[l[i]].pb(d[i]);

    fto(i, 0, n-1) suf+=d[i];

    ans = maxD*maxN; int k = 0;
    fto(x, 1, maxL-1) {
        forit(it, vector<int>, v[x]) suf-=*it;
        k+=v[x].size();

        int cur = 0, sum = suf;
        fto(i, 1, maxD-1)
            if (cur+cnt[i] < k-v[x].size()*2+1) {
                cur+=cnt[i];
                sum+=cnt[i]*i;
            }
            else {
                int tmp = k-v[x].size()*2+1-cur;
                sum+=max(0, i*tmp);
                break;
            }
        ans = min(ans, sum);

        forit(it, vector<int>, v[x]) ++cnt[*it];
    }

    printf("%d", ans);



    return 0;
}