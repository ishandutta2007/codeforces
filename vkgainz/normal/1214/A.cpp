#include <bits/stdc++.h>
using namespace std;
int n, a[100001], cnt[40];
int main()
{
    cin>>n;
    int d,e; cin >> d >> e;
    int ret = 1000000000;
    for(int j= 0;j<=n;j+=(5*e)){
        int i = ((n-j)/d);
        i*=d;
        ret = min(ret,n-(j+i));
    }
    cout << ret << endl;
}