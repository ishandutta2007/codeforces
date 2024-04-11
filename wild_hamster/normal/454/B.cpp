#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;
ll n,k,i,j,a[100500],rez,rezi;

int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    i = 0;
    while (i < n)
    {
        while (a[i] <= a[i+1] && i < n-1)
            i++;
        //cout << i << endl;
        rez++;
        if (rez == 1) rezi = i;
        i++;
    }
    if (rez == 1) cout << 0 << endl;
    else if(rez == 2&&a[n-1] <= a[0]) cout << n-1-rezi << endl;
    else cout << -1 << endl;
    return 0;
}