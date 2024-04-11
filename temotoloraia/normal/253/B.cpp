#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

long long i, l, n, m, j, a[100000];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w+",stdout);
    
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    sort(a, a + n);
    j = 1;
    i = 0;
    while (i < n)
    {
        while (j < n && a[j] <= 2 * a[i])
        {
              j++;
        }
        
        m = max(m, j - i);
        i++;
    }
    
    cout << n - m;
//    system("pause");
    return 0;
}