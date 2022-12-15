#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll p[62];
int main()
{
    p[0]=1;
    for(int i=1;i<62;i++)p[i]=p[i-1]*2;
    ll L,R;
    cin>>L>>R;
    for(int i=61;i>=0;i--)
        if(L>=p[i]&&R>=p[i])L-=p[i],R-=p[i];else 
        if(L<p[i]&&R>=p[i])break;
    if(L==R){puts("0");return 0;}
    for(int i=61;i>=0;i--)
        if(L<p[i]&&R>=p[i]){cout<<p[i+1]-1<<endl;return 0;}
    return 0;
}