#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin>>s;
    string s2=s;
    reverse(s2.begin(),s2.end());
    cout<<s+s2<<endl;
}