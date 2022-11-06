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

int cmp(const void *c1, const void *c2)
{return 0;}

int main()
{   

    string b,a;
    cin >> a;
    b="/";
    for(int i=0; i<a.length(); i++)
        if (a[i]!='/' || b[b.length()-1]!='/')
            b.push_back(a[i]);
    
    if (b.length()!=1 && b[b.length()-1]=='/') b=b.substr(0, b.length()-1);
    cout << b;
    
}