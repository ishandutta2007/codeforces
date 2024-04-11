#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <iostream>

using namespace std;

int n, m;
long long nr;
string s;

int main()
{
    cin>>s;
    for(int i=0; i<s.size()-1; ++i)
        nr=nr*10+s[i]-'0';
    --nr;
    long long sol = nr/4*12+nr/4*4;
    if(nr%4==1 || nr%4==3)
        sol+=7;
    if(s[s.size()-1]=='f')
        ++sol;
    if(s[s.size()-1]=='e')
        sol+=2;
    if(s[s.size()-1]=='d')
        sol+=3;
    if(s[s.size()-1]=='a')
        sol+=4;
    if(s[s.size()-1]=='b')
        sol+=5;
    if(s[s.size()-1]=='c')
        sol+=6;
    cout<<sol<<"\n";

    return 0;
}