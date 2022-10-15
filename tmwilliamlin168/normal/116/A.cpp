#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, total=0, maxt=0;
    cin >> n;
    for(int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        total-=a;
        total+=b;
        if(total>maxt)
            maxt=total;
    }
    cout << maxt;
    return 0;
}