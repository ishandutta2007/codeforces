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
const int N = 2e5 + 10;
const int mod = 1e9 + 7;

int n,m;
char boa[510][510];
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>boa[i];
    }

    for(int i=0;i<n;i++)
    {
        if(i%3==(n%3==0))for(int j=0;j<m;j++)
        {
            boa[i][j]='X';
        }
        else if(i%3==(n%3==0)+1)
        {
            for(int j=0;j<m;j++)
            {
                if(j==0||boa[i][j-1]=='.'&&(i==n-1||boa[i+1][j-1]=='.'))
                {
                    if(j==m-1||boa[i][j+1]=='.'&&(i==n-1||boa[i+1][j+1]=='.'))
                    {
                        boa[i][j]='X';
                        if(i!=n-1)
                        {
                            boa[i+1][j]='X';
                        }
                        break;
                    }
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<boa[i]<<endl;
    }
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	int _;cin>>_;
	while(_--)
    {
        solve();
    }
	return 0;
}