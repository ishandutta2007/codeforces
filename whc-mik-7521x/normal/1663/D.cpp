#include<bits/stdc++.h>
using namespace std;
string s ;
int  x ;
signed main()
{
    cin >> s; 
    cin >> x ;
    if(s == "ABC"s) 
    {
        puts(x <= 1999?"YES":"NO") ;
    }
    else if(s == "ARC"s) 
    {
        puts(x <= 2799?"YES":"NO") ;
        return 0 ;
    }
    else if(s == "AGC"s)
    {
        puts(1200 <= x?"YES":"NO") ;
        return 0 ;
    }
    return 0;
}