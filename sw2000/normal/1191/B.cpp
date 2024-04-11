#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
 
int main()
{
    string str[3];
    int a[30]={0};
 
    for(int i=0;i<3;i++)
    {
        cin>>str[i];
        if(str[i][1]=='m')
        {
            a[str[i][0]-'0']++;
        }
        if(str[i][1]=='p')
        {
            a[str[i][0]-'0'+10]++;
        }
        if(str[i][1]=='s')
        {
            a[str[i][0]-'0'+20]++;
        }
    }
    for(int i=0;i<30;i++)
    {
        if(a[i]==3)
        {
            cout<<0;
            return 0;
        }
    }
 
    for(int i=0;i<28;i++)
    {
        if(a[i]&&a[i+1]&&a[i+2])
        {
            cout<<0;
            return 0;
        }
    }
 
    for(int i=1;i<30;i++)
    {
        if(a[i]==2)
        {
            cout<<1;
            return 0;
        }
    }
 
    for(int i=0;i<29;i++)
    {
        if(a[i]&&a[i+1])
        {
            cout<<1;
            return 0;
        }
    }
 
    for(int i=1;i<28;i++)
    {
        if(i==9||i==19)continue;
        if(a[i]&&a[i+2])
        {
            cout<<1;
            return 0;
        }
    }
 
    cout<<2;
    return 0;
}