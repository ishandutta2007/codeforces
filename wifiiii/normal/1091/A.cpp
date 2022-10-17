#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<stdio.h>
using namespace std;


int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int m = min(min(a,b-1),c-2);
    cout<<3*(m+1)<<endl;
}