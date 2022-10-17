#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin>>n;
    int c1 = 0, c2 = 0;
    for(int i=1;i<=n;++i)
    {
        int t;
        cin>>t;
        if(t==1) c1 = i;
        else c2 = i;
    }
    cout << min(c1,c2) << endl;

}