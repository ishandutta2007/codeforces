
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int maxn = 2e5+5;

int a[maxn];
int main()
{
    int n,z;
    cin>>n>>z;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+1+n);
    int lo = 0, hi = n/2;
    while(lo<hi)
    {
        int mid = (lo+hi+1)/2;
        int ok = 1;
        int i = mid, j = n;
        while(i>0)
        {
            if(a[j]-a[i]<z) {ok=0;break;}
            i--,j--;
        }
        if(ok) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << endl;
}