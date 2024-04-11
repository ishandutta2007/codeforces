#include<bits/stdc++.h>
using namespace std;

int fib[40]{1,1};
int main()
{
//    for(int i=2;i<20;i++)
//    {
//        fib[i]=fib[i-1]+fib[i-2];
//        cout<<fib[i]<<endl;
//    }
    string s;
    cin>>s;
    int cnt=0;
    for(int i=2;i<s.size();i++)
    {
        char c=s[i-1]+s[i-2]-'A';
        if(c>'Z')c-=26;
        if(c!=s[i])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}