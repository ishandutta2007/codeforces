#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a,b;
    int p;
    long long s1=0,s2=0;
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        if(t>0)
            a.push_back(t),p=1,s1+=t;
        else
            b.push_back(-t),p=2,s2-=t;
    }
    printf( ( ( (s1>s2)                     ) ||
              ( (s1==s2) && (a>b)           ) ||
              ( (s1==s2) && (a==b) &&(p==1) )    ) ?
           "first":"second");
}