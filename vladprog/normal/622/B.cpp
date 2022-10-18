#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int a;
    cin>>s>>a;
    int h1=((int)s[0]-48)*10+(int)s[1]-48,
        m1=((int)s[3]-48)*10+(int)s[4]-48,
        t1=h1*60+m1,
        t2=(t1+a)%1440,
        h2=t2/60,
        m2=t2%60;
    printf("%02d:%02d\n",h2,m2);
}