
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int a[105];
int main()
{
    int n;
    cin>>n;
    int ans = 0;
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
        if(i>1)
        {
            if(a[i]+a[i-1]==5)
            {
                cout << "Infinite" << endl;
                return 0;
            }
            if(a[i]+a[i-1]==3)
            {
                ans += 3;
            }
            if(a[i]+a[i-1]==4)
                ans += 4;
        }
        if(i>2)
        {
            if(a[i-2]==3&&a[i-1]==1&&a[i]==2) ans--;
        }
    }
    cout << "Finite" << endl;
    cout << ans << endl;
}