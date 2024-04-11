#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    set<int> s;
    for(int i=1;i<=n*k;i++)
        s.insert(i);
    int a[k];
    for(int i=0;i<k;i++)
    {
        scanf("%d",&a[i]);
        s.erase(a[i]);
    }
    for(int i=0;i<k;i++)
    {
        printf("%d",a[i]);
        for(int i=1;i<n;i++)
        {
            set<int>::iterator b=s.begin();
            printf(" %d",*b);
            s.erase(b);
        }
        printf("\n");
    }
}