#include <iostream>

using namespace std;

int main()
{
    long int n,tmp,i;
    cin>>n;
    do
    {
        tmp=n%10;n/=10;
        if (tmp>=5) cout<<"-O|";else cout<<"O-|";
        for(i=0;i<(tmp%5);i++) cout<<"O";
        cout<<"-";
        for(i=0;i<4-(tmp%5);i++) cout<<"O";
        cout<<endl;
    }
    while(n);
}