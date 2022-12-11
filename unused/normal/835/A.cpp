#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    int A=a*b+d*2;
    int B=a*c+e*2;
    if(A>B) cout<<"Second";
    else if(A<B) cout<<"First";
    else cout<<"Friendship";
}