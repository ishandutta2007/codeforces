
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

int a[100005];
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int er = (n-11)/2;
    int a=er,b=er;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='8' && b) b--,s[i]=0;
    }
    if(b)
    {
        cout << "NO" << endl;
        return 0;
    }
    for(int i=0;i<n;++i)
    {
        if(!s[i]) continue;
        if(s[i]!='8')
        {
            a--;
            if(a<0) break;
        }
        else
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}