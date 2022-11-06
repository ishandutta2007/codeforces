#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

#define maxn 2000010

int n, m, l, r;
int sol[maxn];
string s;

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    cin>>s;

    n=s.size();

    l=r=maxn/2;
    sol[l]=n;

    for(int i=n-2; i>=0; --i)
    {
        if(s[i]=='l')
            sol[++r]=i+1;
        else
            sol[--l]=i+1;
    }

    for(int i=l; i<=r; ++i)
        printf("%d\n", sol[i]);

    return 0;
}