#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    long i;
    char s[100001];
    cin>>s;
    for(i=0;i<=(strlen(s)/2);i++)
    {
        if ((s[i]==s[strlen(s)-i-1])&&((s[i]==65)||(s[i]==72)||(s[i]==73)||(s[i]==77)||(s[i]==79)||((s[i]>=84)&&(s[i]<=89))))
        {}else {cout<<"NO";return 0;}
    }
    cout<<"YES";
}