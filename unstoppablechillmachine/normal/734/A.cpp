#include <bits/stdc++.h>

using namespace std;

#define itn int
#define fro for

string s;
int a,d,n;


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    cin>>s;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='D') d++;
        if (s[i]=='A') a++;
    }

    if (d>a) cout<<"Danik";
    else if (d==a) cout<<"Friendship";
    else cout<<"Anton";



    return 0;
}