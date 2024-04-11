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
const int mod=1e9+7;

vi ans;
int main()
{
    srand(time(0));
	ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
	int n,k;cin>>n>>k;
	for(int i=0;i<k;i++)
    {
        ans.push_back(i);
        ans.push_back(i);
        for(int j=k-1;j>i+1;j--)
        {
            ans.push_back(j);
            ans.push_back(i);
        }
    }
    for(int i=k-2;i>0;i--)ans.push_back(i);
//    for(auto i:ans)cout<<i;cout<<endl;
    for(int i=0;i<n;i++)cout<<(char)(ans[i%ans.size()]+'a');
	return 0;
}