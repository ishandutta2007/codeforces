#include<iostream>
using namespace std;
int counter;
int main()
{
    int n;
    cin>>n;
    int a,b,c;
    int masivi[n];
    for (int i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        masivi[i]=0;
        masivi[i]=masivi[i]+a+b+c;
    }
    for (int i=0;i<n;i++)
    {
        if (masivi[i]>1)
        counter++;
    }
    cout<<counter<<endl;
     //system("pause");
    //return 0;
}