#include<bits/stdc++.h>
using namespace std;
int main()
{
    pair<int,char>p[4];
    char b='A';
    for(int i=0;i<4;i++)
    {
        string s;
        cin>>s;
        p[i].first=s.length()-2;
        p[i].second=b;
        b++;
        
    }
    sort(p,p+4);
    if(2*p[0].first<=p[1].first &&p[3].first>=2*p[2].first )
    cout<<" C";
    else if(2*p[0].first<=p[1].first)
    cout<<p[0].second;
    else if(p[3].first>=2*p[2].first)
    cout<<p[3].second;
    else
    cout<<"C";
}