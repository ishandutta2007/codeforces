#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,m,x,y; cin >> n >> m >> x >> y;
        y=min(y,x*2);
        bool arr[n+2][m+2]; char temp;
        ms(arr,0);
        for (int i=1;i<=n;++i){
            for (int k=1;k<=m;++k){
                cin >> temp;
                arr[i][k]=(temp=='.');
            }   
        }
        ll cost=0;
        for (int i=1;i<=n;++i){
            for (int k=1;k<=m;++k){
                if (arr[i][k]){
                    if (arr[i][k+1]){
                        arr[i][k+1]=0;
                        cost+=y;
                    }
                    else{
                        cost+=x;
                    }
                }
                arr[i][k]=0;
            }
        }
        cout << cost << '\n';
    }
}