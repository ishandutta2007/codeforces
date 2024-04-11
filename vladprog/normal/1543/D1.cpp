#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

int kxor(int a,int b,int k)
{
//    cout<<a<<"+"<<b<<" = ";
    vector<int> digits;
    while(a||b)
    {
        digits.push_back((a+b)%k);
        a/=k;
        b/=k;
    }
    int ans=0;
    while(!digits.empty())
    {
        ans=ans*k+digits.back();
        digits.pop_back();
    }
//    cout<<ans<<endl;
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int add=0;
        for(int i=0;i<n;i++)
        {
//            cout<<"val = "<<i<<"+"<<add<<" = ";
            int val=kxor(i,add,k);
            cout<<val<<endl;
            int r;
            cin>>r;
            if(r==1)
                break;
            if(r==-1)
                exit(1);
//            cout<<"add = "<<add<<"+"<<val<<" = ";
            add=kxor(add,val,k);
//            cout<<add<<endl;
        }
    }
}