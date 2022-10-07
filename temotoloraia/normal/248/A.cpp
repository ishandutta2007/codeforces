#include<iostream>
using namespace std;
int  c,e,m,n,k;
int main()
{
    int a;
    cin>>a;
    int d,b;
    for(int i=0;i<a;i++)
    {
            cin>>b; c=c+b;
            cin>>d; e=e+d;
}
if (a>=(2*c)) m=c;
if (a<(2*c)) m=a-c;
if (a<=(2*e)) n=a-e;
if (a>(2*e)) n=e;
k=m+n;
cout<<k<<endl;
// system("pause");
return 0;
}