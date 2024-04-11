#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main()
{
    cin>>a>>b>>c>>d;
    if(abs(a-c)==abs(b-d))
    cout<<a<<" "<<d<<" "<<c<<" "<<b;
    else if(a==c)cout<<a+b-d<<" "<<b<<" "<<a+b-d<<" "<<d;
    else if(b==d)cout<<a<<" "<<b+a-c<<" "<<c<<" "<<d+a-c;
    else cout<<-1;
    
}