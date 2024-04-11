#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
using namespace std;
int a[200005],mp[200005];
set<int> st;
vector<int>v;
set<int>::iterator it;
int main() {
    int n,k;
    while(cin>>n>>k)
    {
        v.clear();
        st.clear();
        for(int i=0;i<n;i++)
        {
            int aa;
            scanf("%d",&aa);
            v.push_back(aa);
            st.insert(aa);
            mp[aa]=i;
        }
        int cnt=0;
        int now;
        while(!v.empty())
        {
            cnt++;
            if(cnt&1)
                now=1;
            else
                now=2;
            it=st.end();
            it--;
            int pos=find(v.begin(),v.end(),*it)-v.begin();
            int s=v.size();
            for(int i=max(0,pos-k);i<=min(s-1,pos+k);i++)
            {
                a[mp[v[i]]]=now;
                st.erase(v[i]);
            }
            v.erase(v.begin()+max(0,pos-k),v.begin()+min(s-1,pos+k)+1);
        }
        for(int i=0;i<n;i++)
            cout<<a[i];
        cout<<endl;
    }
    return 0;
}