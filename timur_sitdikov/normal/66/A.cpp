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
#define mp make_pair
#define point complex<double>
#define xx first
#define yy second

void normalize(string &s){
    for(; s.length() < 100; )
        s = "0" + s;
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s, s0, s1, s2, s3;
    cin >> s;
    s0 = "127";
    s1 = "32767";
    s2 = "2147483647";
    s3 = "9223372036854775807";
    normalize(s);
    normalize(s0);
    normalize(s1);
    normalize(s2);
    normalize(s3);
    if (s <= s0)
        printf("byte");
    else if (s <= s1)
        printf("short");
    else if (s <= s2)
        printf("int");
    else if (s <= s3)
        printf("long");
    else 
        printf("BigInteger");
}