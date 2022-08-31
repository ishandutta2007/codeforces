//zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
string str;
int main()
{
    cin>>str;
    bool ok=1;
    for(int i=1;str[i];i++) if(!isupper(str[i])) ok=0;
    if(ok)
    {
        for(int i=0;str[i];i++)
        {
            if(isupper(str[i])) str[i]=tolower(str[i]); else if(islower(str[i])) str[i]=toupper(str[i]);
        }
    }
    cout<<str;
}