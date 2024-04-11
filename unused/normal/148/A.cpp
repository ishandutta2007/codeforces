#include <bits/stdc++.h>
using namespace std;

bool damaged[100005];

int main()
{
    int k,l,m,n,d;
    cin>>k>>l>>m>>n>>d;
    for (int i = k; i <= d; i += k) damaged[i] = true;
    for (int i = l; i <= d; i += l) damaged[i] = true;
    for (int i = m; i <= d; i += m) damaged[i] = true;
    for (int i = n; i <= d; i += n) damaged[i] = true;
    printf("%d\n", accumulate(damaged+1,damaged+1+d,0));
}