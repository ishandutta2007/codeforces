#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

bool state[3][maxn+5];

int main()
{
	int n,q; scanf("%d%d",&n,&q);
	int cnt=0;
	rep(i,1,q) 
	{
		int x,y; scanf("%d%d",&x,&y);
		if(state[x][y]==0) cnt+=state[3-x][y-1]+state[3-x][y]+state[3-x][y+1];
		else cnt-=state[3-x][y-1]+state[3-x][y]+state[3-x][y+1];
		state[x][y]^=1;
		puts(cnt?"No":"Yes");
	}
	return 0;
}