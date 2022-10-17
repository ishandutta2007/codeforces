#include <bits/stdc++.h>

using namespace std;

#define itn int
#define fro for

int k2,k3,k5,k6,kol,sum;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>k2>>k3>>k5>>k6;
    kol=k2;
    kol=min(kol,k5);
    kol=min(kol,k6);
    sum=kol*256;
    k2-=kol;
    sum+=min(k2,k3)*32;
    cout<<sum;


    return 0;
}