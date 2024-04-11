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
        int r,c,a,b; cin >> r >> c >> a >> b;
        bool arr[r][c];
        int cnt;
        bool yes=false;
        for (int shift=0;shift<c;++shift){
            ms(arr,0);
            for (int row=0,l=(row*shift)%c;row<r;++row,l+=shift,l%=c){
                for (int i=0;i<a;++i) arr[row][(l+i)%c]=1;
            }
            bool flag=true;
            for (int i=0;i<c;++i){
                cnt=0;
                for (int k=0;k<r;++k){
                    cnt+=arr[k][i];
                }
                flag&=cnt==b;
            }
            if (flag){
                yes=true;
                cout << "yes" << '\n';
                for (int i=0;i<r;++i){
                    for (int k=0;k<c;++k){
                        cout << arr[i][k];
                    }
                    cout << '\n';
                }
                break;
            }
        }
        if (!yes) cout << "no" <<'\n';
    }

}