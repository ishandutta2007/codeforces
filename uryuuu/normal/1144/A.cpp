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
int n;
string s;
int flag1=1;
int flag=1;
int a[1000];
int ct=0;
int main()
{
    cin>>n;
    while(n--)
    {
        flag=1;
        cin>>s;
        sort(s.begin(),s.end());
        for(int i=1;i<s.size();i++)
        {
            if((s[i]-'0')!=(s[i-1]-'0')+1)
                flag=0;
        }
        if(flag==0)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}