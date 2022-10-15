#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int count=0, a_k=-1;
    for(int i=1; i<=n; ++i) {
        int a;
        cin >> a;
        if(a==0)
            break;
        if(a_k==-1||a_k==a)
            ++count;
        else
            break;
        if(i==k)
            a_k=a;
    }
    cout << count;
    return 0;
}