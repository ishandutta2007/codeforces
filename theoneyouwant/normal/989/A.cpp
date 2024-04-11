/*
Copyright SHUBHAM ANAND JAIN, IIT BOMBAY
I JUST DID THIS CAUSE IT WAS FUN :P 
*/

#include<bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char a,b,c;
    int x=0;
    cin>>a>>b;
    while(cin>>c)
    {
        if((a=='A'&&b=='B'&&c=='C') || (a=='A'&&b=='C'&&c=='B') || (a=='B'&&b=='A'&&c=='C') || (a=='B'&&b=='C'&&c=='A') || (a=='C'&&b=='A'&&c=='B') || (a=='C'&&b=='B'&&c=='A'))
        {
            x=1;
            break;
        }
        a=b;
        b=c;
    }
    if(x==1)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
     return 0;
}