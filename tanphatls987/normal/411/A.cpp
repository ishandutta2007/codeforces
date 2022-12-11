#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

int main()
{
    char s[101];
    int i,x,y,z;
    cin>>s;
    x=0;y=0;z=0;
    for(i=0;i<strlen(s);i++)
    {
        if ((s[i]>=65)&&(s[i]<=90)) x=1;
        if ((s[i]>=48)&&(s[i]<=57)) y=1;
        if ((s[i]>=97)&&(s[i]<=122)) z=1;
    }
    if ((strlen(s)>=5)&&(x)&&(y)&&(z)) cout<<"Correct" ;else cout<< "Too weak";
}