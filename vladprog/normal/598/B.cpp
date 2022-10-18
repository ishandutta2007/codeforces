#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    int m;
    cin>>s>>m;
    auto b=s.begin();
    for(int i=0;i<m;i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        l--,r--;
        int len=r-l+1;
        k=(len-k%len)%len;
        r++;
        rotate(b+l,b+l+k,b+r);
    }
    cout<<s;
}