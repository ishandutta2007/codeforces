#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#define uint long long int
using namespace std;
char buff[60];
int main()
{
    scanf("%s", buff+1);
    int licz=1;
    if(buff[licz]=='h')
    {
        cout<<"ht";
        licz=6;
    }
    else
    {
        cout<<"f";
        licz=5;
    }
    cout<<"tp://";
    int dlug=1;
    while(buff[dlug])
    {
        dlug++;
    }
    dlug--;
    int ru=dlug+1;
    for(int i=licz; i<=dlug; i++)
    {
        if(buff[i]=='r' && buff[i+1]=='u')
        {
            ru=i;
            break;
        }
    }
    for(int i=licz-1; i<ru; i++)
    {
        cout<<buff[i];
    }
    cout<<".ru";
    if(ru+1<dlug)
    {
        cout<<"/";
        for(int i=ru+2; i<=dlug; i++)
        {
            cout<<buff[i];
        }
    }
    cout<<endl;
    //system("pause");
    return 0;
}
/*
httpkuparu
*/
/*
httpruru
*/