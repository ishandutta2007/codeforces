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
    string ss;
    cin>>ss;
    for(int i=0;i<ss.length();i++)
    {
        char s=tolower(ss[i]);
        if(s=='a'||s=='e'||s=='i'||s=='u'||s=='o'||s=='y') continue;
        putchar('.'); putchar(s);
    }
}