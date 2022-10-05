#include<iostream>
#include<string>
using namespace std;
string a1,b1;
int a[1005],b[1005],sum[1005];
int x,r,len;
int main()
{
    cin>>a1>>b1;
    r=-100000;
    for(int i=0;i<a1.length();i++) 
    {
        r=max(r,a1[i]-48);
        a[a1.length()-1-i]=a1[i]-48;
    }
    for(int i=0;i<b1.length();i++) 
    {
        r=max(r,b1[i]-48);
        b[b1.length()-1-i]=b1[i]-48;
    }
    r++;len=0;
    while(len<=a1.length()||len<=b1.length())
    {
        sum[len]=a[len]+b[len]+x;
        x=sum[len]/r;   
        sum[len++]%=r;
    }
    while(!sum[len]&&len>0) len--;
    len++;
    cout<<len<<endl;
    return 0;
}