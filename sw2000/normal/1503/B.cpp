#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int n;
int boa[110][110];
int main()
{
	cin>>n;
	vector<pii> v[2];
	for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((i+j)%2)
            {
                v[1].push_back({i,j});
            }
            else
            {
                v[0].push_back({i,j});
            }
        }
    }
	for(int _=0;_<n*n;_++)
    {
        int a;cin>>a;
        if(v[0].empty())
        {
            if(a==2)cout<<3<<' ';
            else cout<<2<<" ";
            cout<<v[1].back().fi<<' '<<v[1].back().se<<endl;
            v[1].pop_back();
        }
        else if(v[1].empty())
        {
            if(a==1)cout<<3<<' ';
            else cout<<1<<" ";
            cout<<v[0].back().fi<<' '<<v[0].back().se<<endl;
            v[0].pop_back();
        }
        else if(a!=1)
        {
            cout<<"1 "<<v[0].back().fi<<' '<<v[0].back().se<<endl;
            v[0].pop_back();
        }
        else
        {
            cout<<"2 "<<v[1].back().fi<<' '<<v[1].back().se<<endl;
            v[1].pop_back();
        }
    }
	return 0;
}