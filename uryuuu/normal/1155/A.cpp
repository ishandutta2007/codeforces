#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#define ll long long
int inf=0x3f3f3f3f;
using namespace std;
int main()
{
    string s;
    int n;
    cin>>n;
    cin>>s;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]>s[i+1])
        {
            cout<<"YES"<<endl;
            cout<<i+1<<' '<<i+2<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}