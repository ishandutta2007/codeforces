#include <bits/stdc++.h>
#define ff(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
using namespace std;

int a[5];
int cnt[105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int sum = 0;
    ff(i,0,4){
        cin >> a[i];
        sum += a[i];
        cnt[a[i]]++;
    }

    int ans = sum;
    ff(i,1,100){
        if(cnt[i] == 2) ans = min(ans, sum - i * 2);
        if(cnt[i] > 2) ans = min(ans, sum - i * 3);
    }

    cout << ans;
}