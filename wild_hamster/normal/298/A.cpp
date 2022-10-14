#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <cstring>
#include <string.h>
using namespace std;
int main() {
int m,n,a[100000],s,t,i,j,k;
string c;
cin>>n;
cin>>c;
for (i=0;i<c.size();i++)
if (c[i]!='.') {s=i;break;}
for (i=s;i<c.size();i++)
if (c[i]=='L') {t=i;break;} else
if (c[i]=='.') {t=i+1;break;}
cout<<s+1<<" "<<t;
//system("pause");
return 0;
}