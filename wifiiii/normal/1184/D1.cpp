#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forjj for(int j=1;j<=m;++j)
#define forij for(int i=1;i<=m;++i)

int main()
{
    int n,k,m,t;
    cin>>n>>k>>m>>t;
    vector<int> v;
    forii if(i==k) v.push_back(2); else v.push_back(1);
    while (t--) {
        int x,y;
        cin>>x>>y;
        if(x)
        {
            v.insert(v.begin()+y-1,1);
        }
        else
        {
            int l=0;
            for(int i=0;i<v.size();++i)
            {
                if(v[i]==2) {l=1;break;}
                if(i==y-1) break;
            }
            vector<int> v2;
            if(l) for(int i=0;i<y;++i) v2.push_back(v[i]);
            else for(int i=y;i<v.size();++i) v2.push_back(v[i]);
            v=v2;
        }
        //for(int i:v) cout<<i<<" ";cout<<endl;
        cout<<v.size()<<" "<<find(v.begin(),v.end(),2)-v.begin()+1<<endl;
    }
}