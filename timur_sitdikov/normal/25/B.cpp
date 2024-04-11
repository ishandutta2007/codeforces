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

string s;

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int i, n;
    cin >> n >> s;
    for(i=0; i<n-3; i+=2)
        cout << s[i] << s[i+1] << "-";
    for(; i<n; i++)
        cout << s[i];

}