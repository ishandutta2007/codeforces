#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e6+100;

int d1[N],d2[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size();
        {
            for(int i=0;i<n;i++)
                d1[i]=0;
            int l=0, r=-1;
            for (int i=0; i<n; ++i) {
              int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
              while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
              d1[i] = k;
              if (i+k-1 > r)
                l = i-k+1,  r = i+k-1;
            }
        }
        {
            for(int i=0;i<n;i++)
                d2[i]=0;
            int l=0, r=-1;
            for (int i=0; i<n; ++i) {
              int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
              while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
              d2[i] = k;
              if (i+k-1 > r)
                l = i-k,  r = i+k-1;
            }
        }
        int eq=0;
        for(int i=0,j=n-1;i<j&&s[i]==s[j];i++,j--)
            eq=i+1;
        array<int,3> ans={2*eq,-1,-1};
        for(int i=0;i<n;i++)
        {
            {
                int l=i-d1[i]+1;
                int r=i+d1[i]-1;
                int add=min((l-1)-(0)+1,(n-1)-(r+1)+1);
                if(add<=eq)
                    ans=max(ans,{r-l+1+2*add,i,1});
            }
            {
                int l=i-d2[i];
                int r=i+d2[i]-1;
                int add=min((l-1)-(0)+1,(n-1)-(r+1)+1);
                if(add<=eq)
                    ans=max(ans,{r-l+1+2*add,i,2});
            }
        }
        if(ans[1]==-1)
            cout<<s.substr(0,eq)<<s.substr(n-eq,eq)<<"\n";
        else if(ans[2]==1)
        {
            int i=ans[1];
            int l=i-d1[i]+1;
            int r=i+d1[i]-1;
            int add=min((l-1)-(0)+1,(n-1)-(r+1)+1);
//            cout<<add<<"+"<<l<<".."<<r<<"+"<<add<<" -> "<<ans[0]<<" -> ";
            cout<<s.substr(0,add)<<s.substr(l,r-l+1)<<s.substr(n-add,add)<<"\n";
        }
        else if(ans[2]==2)
        {
            int i=ans[1];
            int l=i-d2[i];
            int r=i+d2[i]-1;
            int add=min((l-1)-(0)+1,(n-1)-(r+1)+1);
//            cout<<add<<"+"<<l<<".."<<r<<"+"<<add<<" -> "<<ans[0]<<" -> ";
            cout<<s.substr(0,add)<<s.substr(l,r-l+1)<<s.substr(n-add,add)<<"\n";
        }
    }
}