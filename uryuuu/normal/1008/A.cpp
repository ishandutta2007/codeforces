#include<iostream>
#include<cstring>
using namespace std;
char c[103];
int pd(int a)
{
    if (c[a]=='a'||c[a]=='e'||c[a]=='i'||c[a]=='o'||c[a]=='u')
        return 1;
    return 0;
}
int main()
{
    int t=0;
    cin>>c;
    for(int i=0;c[i];i++)
    {
        if(pd(i)==0&&c[i]!='n')
        {
            if(pd(i+1)==0)
                t++;
            }
    }
    if(t)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}