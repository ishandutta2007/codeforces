#include<iostream>

using namespace std;

int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
    long long d,e;
    if (a%c>0) d=a/c+1;
    else if(a%c==0) d=a/c;
    if (b%c>0) e=b/c+1;
    else if (b%c==0) e=b/c;
    long long f=d*e;
    cout<<f<<endl;
  //  system("pause");
    return 0;
}