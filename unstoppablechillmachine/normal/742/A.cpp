#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <iterator>

using namespace std;

int n;

int main()
{

    cin>>n;
    if (n==0) {
        cout<<1;
        exit(0);
    }

    if (n%4==1) cout<<8;
    if (n%4==2) cout<<4;
    if (n%4==3) cout<<2;
    if (n%4==0) cout<<6;

    return 0;
}