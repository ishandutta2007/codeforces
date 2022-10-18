#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    string s(2e6,'a');
    int len=0;
    set<int>is;
    for(int i=0;i<2e6;i++)
        is.insert(i);
    for(int i=1;i<=n;i++)
    {
        char c[1000001];
        scanf("%s",c);
        string t=c;
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            int x;
            scanf("%d",&x);
            x--;
            len=max(len,(int)(x+t.length()));
            while(true)
            {
                set<int>::iterator it=is.lower_bound(x);
                if(*it>x+t.length()-1)break;
                s[*it]=t[*it-x];
                is.erase(*it);
            }
        }
    }
    s.resize(len);
    printf("%s",s.c_str());
}