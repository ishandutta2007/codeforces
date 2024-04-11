#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n-1;++i)
    {
        if(s[i]>s[i+1])
        {
            cout << "YES" << endl;
            cout << i+1 << " " << i+2 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}