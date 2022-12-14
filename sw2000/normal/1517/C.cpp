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
const int N = 500 + 10;

int n,arr[N],ans[N][N],cnt,col;
void dfs(int x,int y){
    if(cnt==0)return;
    ans[x][y]=col;
    cnt--;
    if(y!=1&&!ans[x][y-1])dfs(x,y-1);
    if(x!=n&&!ans[x+1][y])dfs(x+1,y);
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    cin>>n;
//srand(time(0));
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        cnt=col=arr[i];
        dfs(i,i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
	return 0;
}