#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <iostream>

using namespace std;

int n, m, sol;
string s;

int main()
{
    cin>>n;
    cin>>s;

    int ok=1;

    for(int i=0; i<s.size(); ++i)
    {
        if(s[i]=='<')
            sol+=ok;
        else
            ok=0;
    }

    ok=1;

    for(int i=s.size()-1; i>=0; --i)
    {
        if(s[i]=='>')
            sol+=ok;
        else
            ok=0;
    }

    printf("%d\n", sol);
    return 0;
}