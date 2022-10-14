#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
using namespace std;
int n,i,j,k, a[505], down[505][505], up[505][505],x,y;
string s;
int main() {
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d",&x);
        if (x%2)
        {
            cout << "First" << endl;
            return 0;
        }
    }
    cout << "Second" << endl;
    return 0;
}