#include <iostream>
#include <cstdio>

using namespace std;
const int MAXN = 105;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("calcpower.inp","r",stdin);
    /reopen("calcpower.out","w",stdout);
    #endif // ONLINE_JUDGE
    int n, p1, p2, p3, t1, t2, time1 = 0, time2=0, time3 = 0;
    int l[MAXN], r[MAXN];
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    for(int i=0; i < n ; i++) {
        cin >> l[i] >> r[i];
        time1 +=r[i]-l[i];
    }
    for(int i = 1; i < n; i++){
        int t = l[i] - r[i-1];
        time1 += (t < t1? t : t1);
        t -= t1;
        if (t <= 0) continue;
        time2 += (t < t2? t : t2);
        t -= t2;
        if (t <= 0) continue;
        time3 += t;
    }
    cout << time1*p1 + time2*p2 + time3*p3 << endl;
    return 0;
}