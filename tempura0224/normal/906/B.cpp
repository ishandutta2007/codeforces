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
    int n,m;
    cin>>n>>m;
    if(n==1&&m==1){
        cout<<"YES"<<endl;
        cout<<1<<endl;
        return 0;
    }
    if((n<=2&&m<=3)||(n<=3&&m<=2)){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    if(n==1&&m==4){
        cout<<"2 4 1 3"<<endl;
    }
    else if(n==2&&m==4){
        cout<<"5 4 7 2"<<endl;
        cout<<"3 6 1 8"<<endl;
    }
    
    else if(n==3&&m==3){
        cout<<"6 1 8"<<endl;
        cout<<"7 5 3"<<endl;
        cout<<"2 9 4"<<endl;
    }
    else if(n==3&&m==4){
        cout<<"1 3 10 12"<<endl;
        cout<<"6 8 5 7"<<endl;
        cout<<"9 11 2 4"<<endl;
    }
    else if(n==4&&m==1){
        cout<<2<<endl;
        cout<<4<<endl;
        cout<<1<<endl;
        cout<<3<<endl;
    }
    else if(n==4&&m==2){
        cout<<"5 1"<<endl;
        cout<<"4 8"<<endl;
        cout<<"7 3"<<endl;
        cout<<"2 6"<<endl;
    }
    else if(n==4&&m==3){
        cout<<"1 5 3"<<endl;
        cout<<"7 11 9"<<endl;
        cout<<"6 2 4"<<endl;
        cout<<"12 8 10"<<endl;
    }
    else if(n==4&&m==4){
        cout<<"1 3 13 15"<<endl;
        cout<<"6 8 10 12"<<endl;
        cout<<"9 11 5 7"<<endl;
        cout<<"14 16 2 4"<<endl;
    }

    else if(m>=5){
        vector<int> o[n], e[n];
        rep(i,n){
            rep(j,m){
                if((i+j)%2)o[i].push_back(m*i+j+1);
                else e[i].push_back(m*i+j+1);
            }
        }
        rep(i,n){
            for(auto c : o[i])cout<<c<<" ";
            for(auto c : e[i])cout<<c<<" ";
            cout<<endl;
        }
    }
    else if(n>=5){
        vector<int> o[m], e[m];
        rep(i,m){
            rep(j,n){
                if((i+j)%2)o[i].push_back(i+m*j+1);
                else e[i].push_back(i+m*j+1);
            }
        }
        vector<vector<int>> ans(n,vector<int>(m));
        rep(i,m){
            int j=0;
            for(auto c : o[i])ans[j++][i]=c;
            for(auto c : e[i])ans[j++][i]=c;
        }
        rep(i,n){
            rep(j,m)cout<<ans[i][j]<<" ";
            cout<<endl;
        }
    }
    else assert(false);
}