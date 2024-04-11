#include<bits/stdc++.h>
using namespace std;
char a[105];
#define x 'x'
int main()
{
    int m;
    cin>>m;
    scanf("%s",a);
    int ans=0;
    for(int i=2;i<m;i++)
    {
        if(a[i]==x&&a[i-1]==x&&a[i-2]==x)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}