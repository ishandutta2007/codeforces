#include<iostream>
using namespace std;
int main()
{
    int shovels, price, r;
    cin>> price>>r;
    int i;
    for(int i=1; i<100000; i++)
    {
        if(r == (price*i)%10 || (price*i)%10 == 0)
        {
            cout<<i;
            break;
 
        }
        
        
    }
}