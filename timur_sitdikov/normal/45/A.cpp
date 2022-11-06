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
#include <complex>
using namespace std;
#define pb push_back

string s[12];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    s[1]="January";
s[2]="February";
s[3]="March";
s[4]="April";
s[5]="May";
s[6]="June";
s[7]="July";
s[8]="August";
s[9]="September";
s[10]="October";
s[11]="November";
s[0]="December";

    int d, i;
    string tmp;
    cin >> tmp >> d;
    for(i=0; i<12; i++)
        if (s[i]==tmp)
            break;
    i=(i+d)%12;
    cout << s[i];
        

}