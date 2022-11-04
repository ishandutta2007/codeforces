#include<iostream>
using namespace std;
int main()
{
    int t,a,b;
    long long s,k;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>k;
        if(k%2)
            s=(a-b)*(k/2)+a;
        else
            s=(a-b)*(k/2);
        cout<<s<<endl;
    }
    return 0;
}