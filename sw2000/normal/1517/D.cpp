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

int n,m,k,ans[N][N],tmp[N][N],arr[N][N],brr[N][N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            cin>>brr[i][j];
        }
    }
    if(k%2){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)cout<<-1<<' ';
            cout<<endl;
        }
        return 0;
    }
    for(int x=1;x<=k/2;x++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                tmp[i][j]=inf;
                if(i)tmp[i][j]=min(tmp[i][j],brr[i-1][j]+ans[i-1][j]);
                if(j)tmp[i][j]=min(tmp[i][j],arr[i][j-1]+ans[i][j-1]);
                if(i!=n-1)tmp[i][j]=min(tmp[i][j],brr[i][j]+ans[i+1][j]);
                if(j!=m-1)tmp[i][j]=min(tmp[i][j],arr[i][j]+ans[i][j+1]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=tmp[i][j];
//                cout<<ans[i][j]<<" ";
            }
//            cout<<endl;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cout<<ans[i][j]*2<<' ';
        cout<<endl;
    }
	return 0;
}