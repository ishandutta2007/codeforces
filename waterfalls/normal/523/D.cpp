#include <bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int a,b; scanf("%I64d %I64d", &a, &b); 
    multiset <int> o; 
    for (int g=1; g<=a; g++)
    {
        int c,d; scanf("%I64d %I64d", &c, &d); 
        if (b)
        {
            o.insert(c+d); 
            printf("%I64d\n", c+d); 
            b--; 
        }
        else
        {
            int r=max(c, *o.begin())+d; 
            printf("%I64d\n", r); 
            o.erase(o.begin()); 
            o.insert(r); 
        }
    }    
    return 0; 
}