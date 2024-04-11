#include<iostream>
#include<string>
using namespace std;
string ss;
int a,i,k;
int main()
{
    cin>>a;
    
    for(i=0;i<a;i++)
    
    { cin>>ss;
    if(ss[0]=='+' || ss[2]=='+')
    k++;
    else k--;}
    cout<<k;
//system("pause");
    return 0;
}