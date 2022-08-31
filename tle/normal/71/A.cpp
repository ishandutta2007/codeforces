#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
int main()
{
    int n;
    string ss;
    cin>>n;
    while(n--)
    {
        cin>>ss;
        if(ss.length()<=10) cout<<ss;
        else
        {
            cout<<*ss.begin()<<ss.length()-2<<*((ss.end())-1);
        }
        cout<<"\n";
    }
}