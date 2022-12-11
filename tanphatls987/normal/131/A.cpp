#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

#define check() printf("tick\n")
using namespace std;

const int maxi=100000;

string s;
int key,change,i;
int main()
{
    cin>>s;
    change=1;
    for(i=1;i<s.length();i++) if (s[i]>='a'&&s[i]<='z') change=0;
    key='a'-'A';
    if (change) {for(i=0;i<s.length();i++) if (s[i]<='Z') s[i]+=key;else s[i]-=key;}
    cout<<s;
}