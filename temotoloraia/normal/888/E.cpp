#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n, m;
int a[40];
int b[2];
set < int > S[2];
int ans;
void go (int k, int s, int p){
    if (k > b[p]){
        S[p].insert(s);
        return;
    }
    go (k + 1, s, p);
    s += a[k];
    if (s > m)
        s -= m;
    go (k + 1, s, p);
}
int main()
{
    cin>>n>>m;
    for (int i = 1; i <= n; i++){
        cin>>a[i];
        a[i] %= m;
    }
    S[0].insert(0);
    S[1].insert(0);
    b[0] = n / 2;
    b[1] = n;
    go (1, 0, 0);
    go (n / 2 + 1, 0, 1);
    for (set < int >:: iterator I = S[0].begin(); I != S[0].end(); I++){
            set<int>::reverse_iterator rit = S[1].rbegin();
        ans = max (ans, ((*I) +
                         (*(rit)))
                   % m);
        set < int >:: iterator it = S[1].lower_bound(m - (*I));
        if (it == S[1].begin())
            continue;
        it--;
        ans = max (ans, ((*I) + (*it)) % m);
    }
    cout<<ans<<endl;
    return 0;
}