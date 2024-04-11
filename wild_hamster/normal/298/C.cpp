#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <cstring>
#include <string.h>
using namespace std;
int main() {
int m,n,a[100000],s1,s2,t,i,j,k;
string c1,c2;
getline(cin,c1);
getline(cin,c2);
s1=0;s2=0;
for (i=0;i<c1.size();i++) if (c1[i]=='1') s1++;
for (i=0;i<c2.size();i++) if (c2[i]=='1') s2++;
if (s1>=s2||(s1%2==1&&s1+1==s2)) cout<<"YES"; else cout<<"NO";
//system("pause");
return 0;
}