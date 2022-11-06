#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#define pb push_back

string s;
string ans;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i;
    cin >>s;
    for(i=0; i<(int)s.length(); )
        if (s[i]=='.')
        {
            ans.pb('0');
            i++;
        }
        else if (s[i+1]=='.')
        {
            ans.pb('1');
            i+=2;
        }
        else 
        {
            ans.pb('2');
            i+=2;
        }
        cout << ans;
}