#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#include<string>
#include<cmath>
typedef long long ll;
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int tar = 1;
    for(int i=1;i*i<=n;++i)
    {
        if(n%i==0)
        {
            if(i<=k-1) tar=max(tar,i);
            if(n/i<=k-1) tar=max(tar,n/i);
        }
    }
    cout<<n/tar*k+tar<<endl;
}