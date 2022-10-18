#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d\n",&n);
    string s[n];
    for(int i=0;i<n;i++)
    {
        char c[500000];
        scanf("%s",c);
        s[i]=c;
    }
    for(int i=n-2;i>=0;i--)
    {
        int l=1,r=s[i].length()+1;
        while (r-l>1)
        {
            int m=(l+r)/2;
            if(string(s[i],0,m)<=s[i+1])
                l=m;
            else
                r=m;
        }
        s[i].resize(l);
    }
    for(int i=0;i<n;i++)
        cout<<s[i]<<endl;
}