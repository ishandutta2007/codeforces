/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <numeric>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    vector<int> f(101);
    for (int i = 0; i < n ;i++) {
        cin >> a[i];
        ++f[a[i]];
    }
    cout << *max_element(f.begin(), f.end());
}