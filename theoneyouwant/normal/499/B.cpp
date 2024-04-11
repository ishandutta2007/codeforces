#include<iostream>
#include<map>
using namespace std;
int main()
{
    map <string,string> ma;
    string s1,s2;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>s1>>s2;
        if(s1.length()<=s2.length())
        {
            ma[s1] = s1;
        }
        else 
        {
            ma[s1] = s2;
        }
    }
    for(int i=0;i<n;i++)
    {
        cin>>s1;
        cout<<ma[s1]<<" ";
    }
    return 0;
}