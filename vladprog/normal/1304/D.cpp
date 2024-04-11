#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        {
            vector<int> v{1};
            for(char c:s)
                if(c=='>')
                    v.push_back(1);
                else
                    v.back()++;
            int sum=0;
            for(int x:v)
            {
                for(int i=sum+x;i>=sum+1;i--)
                    cout<<n+1-i<<" ";
                sum+=x;
            }
            cout<<"\n";
        }
        {
            vector<int> v{1};
            for(char c:s)
                if(c=='<')
                    v.push_back(1);
                else
                    v.back()++;
            int sum=0;
            for(int x:v)
            {
                for(int i=sum+x;i>=sum+1;i--)
                    cout<<i<<" ";
                sum+=x;
            }
            cout<<"\n";
        }
    }
}