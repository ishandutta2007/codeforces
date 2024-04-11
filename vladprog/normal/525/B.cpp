#include<bits/stdc++.h>

using namespace std;

const int inf=1000;

int main()
{
    string s;
    int m;
    cin>>s>>m;
    int n=s.length(),a[n];
    memset(a,0,sizeof(a));
    for(int i=0;i<m;i++)
    {
        int c;
        cin>>c;
        //printf("a[%i] : %i -> %i\n",c-1,a[c-1],a[c-1]+1);
        a[c-1]++;
    }
    if(a[0]%2)
        swap(s[0],s[n-1]);
    //cout<<a[0];
    for(int i=1;i<n/2;i++)
    {
        if((a[i]+=a[i-1])%2)
            swap(s[i],s[n-i-1]);
        //cout<<a[i];
    }
    cout<<s;
}