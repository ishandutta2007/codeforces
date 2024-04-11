#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
    int i,x,n,s,y,rez;
int main()
{
    rez = -1;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (x < s) rez = max(rez,(100-y)%100);
        if (x == s && y == 0) rez = max(rez, 0);
    }
    cout << rez << endl;
    return 0;
}