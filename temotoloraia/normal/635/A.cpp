#include <iostream>
#include <fstream>
using namespace std;
int k,k1,a,b,c,d,a1,a2,n[100][100];
main()
{
cin>>a>>b>>c>>d;
for (int i=0;i<c;i++)
{
    cin>>a1>>a2;
    n[a1-1][a2-1]=1;
}
for (int i1=0;i1<a;i1++){
for (int i2=0;i2<b;i2++){
for (int i3=0;i3<a-i1;i3++){
for (int i4=0;i4<b-i2;i4++){
for (int i5=0;i5<i1+1;i5++){
for (int i6=0;i6<i2+1;i6++){
    if (n[i3+i5][i4+i6]==1) k++;
}}
    if (k>=d) k1++;
    k=0;
}}}}
cout<<k1<<endl;
return 0;
}