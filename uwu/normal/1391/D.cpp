#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define pc(x) (__builtin_popcount(x))
#define get(x,idx) (1&(x>>idx))
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e6+1;

int n,m;
int last[9], curr[9];
int arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    if (n>=4){ cout << -1 << '\n'; return 0; }
    if (n==1){ cout << 0 << '\n'; return 0; }
    char a;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin >> a;
            arr[j]+=(1<<(i-1))*(a=='1');
        }
    }
    if (n==2){
        for (int i=0;i<4;++i) curr[i]=pc(i^arr[1]);
        for (int idx=2;idx<=m;++idx){
            swap(curr,last); ms(curr,0x3f);
            for (int i=0;i<4;++i){
                for (int j=0;j<4;++j){
                    if ((pc(i)+pc(j))%2==0) continue;
                    curr[j]=min(curr[j],last[i]+pc(arr[idx]^j));
                }
            }
        }
        int ans=0x3f3f3f3f;
        for (int i=0;i<4;++i) ans=min(ans,curr[i]);
        cout << ans << '\n';
    }
    if (n==3){
        for (int i=0;i<8;++i) curr[i]=pc(i^arr[1]);
        for (int idx=2;idx<=m;++idx){
            swap(curr,last); ms(curr,0x3f);
            for (int i=0;i<8;++i){
                for (int j=0;j<8;++j){
                    if ((get(i,0)+get(i,1)+get(j,0)+get(j,1))%2==0) continue;
                    if ((get(i,1)+get(i,2)+get(j,1)+get(j,2))%2==0) continue;
                    curr[j]=min(curr[j],last[i]+pc(arr[idx]^j));
                }
            }
        }
        int ans=0x3f3f3f3f;
        for (int i=0;i<8;++i) /*cout << i << " " << curr[i] << '\n',*/ ans=min(ans,curr[i]);
        cout << ans << '\n';
    }
}