#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n,k,i;
    string a;
    cin>>n>>k;
    cin>>a;
    if (k>n-k)
    {
        for(i=k;i<n;i++) printf("RIGHT\n");
        for(i=n-1;i>0;i--) cout<<"PRINT"<<" "<<a[i]<<endl<<"LEFT"<<endl;
        cout<<"PRINT"<<" "<<a[0]<<endl;
    }
    else
    {
        for(i=k;i>1;i--) printf("LEFT\n");
        for(i=0;i<n-1;i++) cout<<"PRINT"<<" "<<a[i]<<endl<<"RIGHT"<<endl;
        cout<<"PRINT"<<" "<<a[n-1]<<endl;
    }
}