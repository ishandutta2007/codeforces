#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n;
    int x=0;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int i=0;i<s.length();i+=3)
        {
            if(s[i+1]=='+') x++; else x--;
        }
    }
    cout<<x;
}