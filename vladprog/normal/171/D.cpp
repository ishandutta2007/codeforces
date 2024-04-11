#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
///               2 4 1 3 5
const int a[6]={0,2,3,1,2,1};
const int b[6]={0,0,0,0,0,0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    cout<<a[n];
    if(b[n])return 1;
}