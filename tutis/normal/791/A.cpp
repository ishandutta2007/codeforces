#include <iostream>
using namespace std;
int main()
{
    long long a, b;
    cin>>a>>b;
    int k=0;
    while(a<=b)
        {
        a*=3;
    b*=2;
    k++;
        }
        cout<<k<<endl;
}