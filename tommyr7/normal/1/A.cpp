#include <bits/stdc++.h>
using namespace std;
long long n,m,a;
int main()
{
    cin>>n>>m>>a;
    n=(n+a-1)/a,m=(m+a-1)/a;
    cout << (long long)n*m<<endl;
    return 0;
}