#include <bits/stdc++.h>
using namespace std;
int main()
{
    char ch;
    string a,b,c="6789TJQKA";
    cin>>ch>>a>>b;
    if((a[1]==b[1]&&c.find(a[0])>c.find(b[0]))||(a[1]==ch&&b[1]!=ch)) cout<<"YES";
    else cout<<"NO";
}