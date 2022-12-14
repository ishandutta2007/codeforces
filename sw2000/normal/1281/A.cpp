#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;

int main()
{
//    freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int len=s.size();
        if(s.substr(len-2,2)=="po")cout<<"FILIPINO"<<endl;
        else if(s.substr(len-4,4)=="desu"||s.substr(len-4,4)=="masu")
            cout<<"JAPANESE"<<endl;
        else cout<<"KOREAN"<<endl;
    }
    return 0;
}