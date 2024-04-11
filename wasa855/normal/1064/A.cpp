#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[4];
    cin>>a[1]>>a[2]>>a[3];
    sort(a+1,a+4);
    printf("%d",max(0,a[3]-a[2]-a[1]+1));
    return 0;
}
//BOME