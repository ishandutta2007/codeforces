#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
multiset<int> s;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        s.insert(b[i]);
    }
    for(int i=1;i<=n;i++)
    {
        multiset<int>::iterator ss=s.lower_bound(n-a[i]);
        if(ss==s.end()) ss=s.begin();
        printf("%d ",(a[i]+*ss)%n);
        s.erase(ss);
    }
    return 0;
}
//aiuwhdusa