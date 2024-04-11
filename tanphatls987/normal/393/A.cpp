#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char a[101];
    long int ans,i,h[26]={0};
    cin>>a;
    for(i=0;i<strlen(a);i++) h[a[i]-97]++;
    ans=((h['n'-97]-1)/2);
    if (ans<0) ans=0;
    if (ans>h['i'-97]) ans=h['i'-97];
    if (ans>h['t'-97]) ans=h['t'-97];
    if (ans>(h['e'-97]/3)) ans=h['e'-97]/3;
    cout<<ans;
}