//For CodeForces Round, By zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[10];
int main()
{
    for(int i=1;i<=6;i++) cin>>a[i];
    sort(a+1,a+7);
    do
    {
        if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4])
        {
            if(a[5]==a[6]) {cout<<"Elephant"; return 0;} else if(a[5]<a[6]) {cout<<"Bear"; return 0;}
        } 
    }while(next_permutation(a+1,a+7));
    cout<<"Alien";
    return 0;
}