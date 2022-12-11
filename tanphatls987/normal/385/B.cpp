#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;

string s;
int start,ans,i,n;
int main()
{
    cin>>s;
    n=s.length();
    start=0;ans=0;
    for(i=0;i<n-3;i++)
    {
        if ((s[i]=='b')&&(s[i+1]=='e')&&(s[i+2]=='a')&&(s[i+3]=='r'))
        {
            ans+=(i-start+1)*(n-i-3);
            start=i+1;
        }
    }
    cout<<ans;
}