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
#define maxN 100000

vector<int> divisor[maxN+1];
int n, dp[maxN+1], d[maxN+1], a[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    fto(i, 2, maxN) {
        int j = i;
        while (j <= maxN) {
            divisor[j].pb(i);
            j+=i;
        }
    }

    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d", &a[i]);
    
    if (n == 1 && a[0] == 1) {
    	printf("1");
    	return 0;
    }
    
    fto(i, 0, n-1) {
    	int x = a[i];
    	forit(it, vector<int>, divisor[x]) dp[x] = max(dp[x], d[*it]+1);
    	forit(it, vector<int>, divisor[x]) d[*it] = dp[x];
    }
    
    int ans = 0;
    fto(i, 0, n-1) ans = max(ans, dp[a[i]]);
    printf("%d", ans);

    return 0;
}