#include<bits/stdc++.h>

using namespace std;

void check(string s)
{
    string t;
    reverse_copy(s.begin(),s.end(),back_inserter(t));
    if(s==t)
        cout<<s,exit(0);
}

int main()
{
    string s;
    cin>>s;
    for(int i=0;i<=s.size();i++)
        for(char c='a';c<='z';c++)
        {
            string t=s;
            t.insert(t.begin()+i,c);
            check(t);
        }
    cout<<"NA";
}