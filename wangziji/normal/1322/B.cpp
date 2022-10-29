#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
 
const int maxn = 4e5 + 7;
 
int n;
long long a[maxn], b[maxn];
 
void Sort(long long *a, long long md) {
    int pos = n;
    for (int i = 0; i < n; i ++) {
        if (pos == n && a[i] >= md) pos = i;
        a[i] = a[i] & (md - 1);
    }
    inplace_merge(a, a + pos, a + n);
}
 
bool solve(long long limit) {
    long long ans = 0;
    int that = n - 1;
    for (int i = 0; i < n-1; i ++) {
        while (that >= 0 && a[i] + b[that] >= limit) that --;
    //    if(that<i)  that=i;
        //if(limit==2)
      //  cout << i << " " << that  << "*"<< endl;
        ans += n -1 - max(that,i);
    }
  //  cout << limit << " "<< ans << endl;
    return ans & 1;
}
signed main() {
    int T=1, cas = 0;
    while (T --) {
        cin >> n;
        for(int i=0;i<n;i++)
        	scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
        	b[i]=a[i];
        sort(a,a+n),sort(b,b+n);
        long long ans=0;
        for(int i=31;i>=0;i--)
        { 
            Sort(a, (long long)2 << i);
            Sort(b, (long long)2 << i);
            long long res =
                solve((long long)1 << i) ^
                solve((long long)2 << i) ^
                solve((long long)3 << i);
            ans |= res << i;
        }
        cout << ans; 
    }
    return 0;
}