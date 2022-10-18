#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=5e5+100;

int m[N],pref[N],suff[N],a[N];

int len(int l,int r)
{
    return r-(l-1);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>m[i];
    vector<int> st{0};
    for(int i=1;i<=n;i++)
    {
        int pos=i;
        while(m[st.back()]>m[i])
            pos=st.back(),
            st.pop_back();
        pos=st.back()+1;
        st.push_back(i);
        pref[i]=pref[pos-1]+len(pos,i)*m[i];
    }
    st={n+1};
    for(int i=n;i>=1;i--)
    {
        int pos=i;
        while(m[st.back()]>m[i])
            pos=st.back(),
            st.pop_back();
        pos=st.back()-1;
        st.push_back(i);
        suff[i]=suff[pos+1]+len(i,pos)*m[i];
    }
    pair<int,int> ans{0,0};
    for(int i=1;i<=n;i++)
        ans=max(ans,{pref[i]+suff[i]-m[i],i});
//    cout<<ans.first<<" "<<ans.y<<"\n";
    a[ans.y]=m[ans.y];
    for(int i=ans.y-1;i>=1;i--)
        a[i]=min(a[i+1],m[i]);
    for(int i=ans.y+1;i<=n;i++)
        a[i]=min(a[i-1],m[i]);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
}