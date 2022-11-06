#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define maxn 200010

int n, m;
string s;
int nb[maxn];

int main()
{
    cin>>n;
    cin>>s;
    int sol=0;
    for(int i=0; i<n; ++i)
    {
        memset(nb, 0, sizeof(nb));
        for(int j=i; j<n; ++j)
        {
            ++nb[s[j]];
            if(nb['U']==nb['D'] && nb['L']==nb['R'])
                ++sol;
        }
    }
    cout<<sol<<"\n";

    return 0;
}