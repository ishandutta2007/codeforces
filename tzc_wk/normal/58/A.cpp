#include<bits/stdc++.h>
using namespace std;
char p[6]="hello",c[1005];
int main()
{
    int x=0;
    cin>>c; 
    for(int i=0;i<strlen(c);i++)
        if(c[i]==p[x]) x++;
    if(x>=5) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}