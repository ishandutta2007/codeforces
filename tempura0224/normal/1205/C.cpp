#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n,-1));
    a[0][0]=1;
    a[0][1]=1;
    a[n-1][n-1]=0;
    rep(i,n)rep(j,n){
        if(a[i][j]==-1){
            cout<<"? "<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+3<<endl;
            int x;
            cin>>x;
            if(x)a[i][j]=a[i][j+2];
            else a[i][j]=a[i][j+2]^1;
        }
        if(i+2<n&&a[i+2][j]==-1){
            cout<<"? "<<i+1<<" "<<j+1<<" "<<i+3<<" "<<j+1<<endl;
            int x;
            cin>>x;
            if(x)a[i+2][j]=a[i][j];
            else a[i+2][j]=a[i][j]^1;
        }
        if(j+2<n&&a[i][j+2]==-1){
            cout<<"? "<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+3<<endl;
            int x;
            cin>>x;
            if(x)a[i][j+2]=a[i][j];
            else a[i][j+2]=a[i][j]^1;
        }
        if(j+1<n&&i+1<n&&a[i+1][j+1]==-1){
            cout<<"? "<<i+1<<" "<<j+1<<" "<<i+2<<" "<<j+2<<endl;
            int x;
            cin>>x;
            if(x)a[i+1][j+1]=a[i][j];
            else a[i+1][j+1]=a[i][j]^1;
        }
    }
    bool ok=false;
    rep(i,n-1){
        if(a[i][i]==a[i+1][i+1]){
            if(i+2<n&&a[i+1][i]==a[i+2][i+1]){
                cout<<"?"<<" "<<i+1<<" "<<i+1<<" "<<i+3<<" "<<i+2<<endl;
                int x;
                cin>>x;
                if(x)ok=(a[i][i]==a[i+1][i]);
                else ok=!(a[i][i]==a[i+1][i]);
                break;
            }
            if(i-1>=0&&a[i][i-1]==a[i+1][i]){
                cout<<"?"<<" "<<i+1<<" "<<i<<" "<<i+2<<" "<<i+2<<endl;
                int x;
                cin>>x;
                if(x)ok=(a[i][i-1]==a[i][i]);
                else ok=!(a[i][i-1]==a[i][i]);
                break;
            }
        }
        else {
            if(i+2<n&&a[i+1][i]!=a[i+2][i+1]){
                cout<<"?"<<" "<<i+1<<" "<<i+1<<" "<<i+3<<" "<<i+2<<endl;
                int x;
                cin>>x;
                if(x)ok=!(a[i][i]==a[i+1][i]);
                else ok=(a[i][i]==a[i+1][i]);
                break;
            }
            if(i-1>=0&&a[i][i-1]!=a[i+1][i]){
                cout<<"?"<<" "<<i+1<<" "<<i<<" "<<i+2<<" "<<i+2<<endl;
                int x;
                cin>>x;
                if(x)ok=!(a[i][i-1]==a[i][i]);
                else ok=(a[i][i-1]==a[i][i]);
                break;
            }
        }
    }
    cout<<"!"<<endl;
    rep(i,n){
        rep(j,n){
            if((i+j)%2)cout<<(a[i][j]^ok^1);
            else cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}