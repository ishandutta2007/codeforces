#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string a;
    cin>>a;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            printf("YES\n%d %d\n",i+1,i+2);
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}