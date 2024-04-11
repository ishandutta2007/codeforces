#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
unordered_map<string,int>mp,id;
int n,m,k;
string s[N];
vector<string>ss[N];
vi ans;
vector<int>v[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        mp[s[i]];
        id[s[i]]=i;
    }
    for(int i=1;i<=m;i++)
    {
        string t;
        int a;
        cin>>t>>a;
        v[a].push_back(i);

        bool f=0;
        for(int j=0;j<(1<<k);j++)
        {
            string tt=t;
            for(int l=0;l<k;l++)if(!(j&1<<l))
            {
                tt[l]='_';
            }
            if(tt==s[a])
            {
                f=1;
            }
            else if(mp.find(tt)!=mp.end())
            {
                ss[i].push_back(tt);
                mp[tt]++;
            }
        }

        if(!f)
        {
            cout<<"NO";
            return 0;
        }
    }
//    for(auto i:mp)
//        cout<<i.fi<<' '<<i.se<<endl;

    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(mp[s[i]]==0)q.push(i);
    }

    while(!q.empty())
    {
        int u=q.front();q.pop();
        ans.push_back(u);
        mp.erase(s[u]);

        for(auto i:v[u])
        {
            for(auto tt:ss[i])
            {
                mp[tt]--;
                if(mp[tt]==0)
                {
                    q.push(id[tt]);
                }
            }
        }
    }
    if(ans.size()==n)
    {
        cout<<"YES"<<endl;
            for(auto i:ans)
        cout<<i<<' ';
    }
    else cout<<"NO"<<endl;
	return 0;
}