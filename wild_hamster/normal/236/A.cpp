#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
using namespace std;
typedef long long ll;
ll m,k1,k2,j,n,i,max1,a[60000];
int main()
{
    string s;
    cin>>s;
    for (i=0;i<6000;i++) a[i]=0;
    for (i=0;i<s.size();i++) 
a[(int)s[i]]=1;
k1=0;
for (i=0;i<6000;i++)
k1+=a[i];
if (k1%2==0) cout<<"CHAT WITH HER!"; else cout<<"IGNORE HIM!";
return 0;
}