#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long m;
vector<int> f, l;

int main()
{
    cin>>n>>m;
    m=m*2-1;

    for(int i=1; i<n; ++i)
    {
        if(((m>>(n-i)&1)==0))
            f.push_back(i);
        else
            l.push_back(i);
    }

    f.push_back(n);

    sort(f.begin(), f.end());
    sort(l.begin(), l.end());

    for(int i=0; i<f.size(); ++i)
        printf("%d ", f[i]);
    for(int i=0; i<l.size(); ++i)
        printf("%d ", l[l.size()-i-1]);

    printf("\n");

    return 0;
}