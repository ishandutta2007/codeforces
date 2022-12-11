#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

#define tick printf("tick\n")
using namespace std;

const int maxd=100000;
int n,i,ans=0,h[30]={0};
string s;
int main()
{
    getline(cin,s);
    for(i=0;i<s.length();i++) if ((s[i]-'a'>=0)&&('z'-s[i]>=0)) h[s[i]-'a']++;
    for(i=0;i<='z'-'a';i++) ans+=(h[i]>0);
    cout<<ans;
}