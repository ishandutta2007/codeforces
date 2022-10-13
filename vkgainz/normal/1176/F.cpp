#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll dp[200001][11];
vector<ll> store[200001][3];
void solve(){
    for(int i=1;i<=n;i++){
        for(int j=0;j<=10;j++){
            dp[i][j] = -10000000000000000;
        }

    }
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        for(int j=0;j<k;j++){
            ll c,d;
            cin >> c >> d;
            store[n-1-i][c-1].push_back(d);
        }
        for(int j=0;j<3;j++){
            sort(store[n-1-i][j].begin(),store[n-1-i][j].end());
        }
    }
    for(int i=0;i<n;i++){
        vector<ll> cards[3];
        for(int j=0;j<3;j++){
            cards[j] = store[i][j];
        }
        for(int x=0;x<10;x++){
            //1, 1 1, 2, 1 1 1 , 1 2, 3
            if(cards[0].size()>=3){
                ll add = dp[i][(x+3)%10];
                ll a = cards[0][cards[0].size()-1];
                ll b=  cards[0][cards[0].size()-2];
                ll c = cards[0][cards[0].size()-3];

                if(x>=7){
                    add+=a+b+c+max(a,(max(b,c)));
                }
                else{
                    add+=a+b+c;
                }
                dp[i+1][x] = max(dp[i+1][x],add);
            }
            if(cards[0].size()>=2){
                ll add = dp[i][(x+2)%10];
                ll a=  cards[0][cards[0].size()-1];
                ll b =cards[0][cards[0].size()-2];
                if(x>=8){
                    add+=a+b+max(a,b);
                }
                else{
                    add+=a+b;
                }
                dp[i+1][x] = max(dp[i+1][x],add);
            }
            if(cards[0].size()>=1){
                ll add = dp[i][(x+1)%10];
                ll a = cards[0][cards[0].size()-1];
                if(x>=9){
                    add+=2*a;
                }
                else{
                    add+=a;
                }
                dp[i+1][x] = max(dp[i+1][x],add);
            }

                
            
            if(cards[0].size()>=1 && cards[1].size()>=1){
                ll add = dp[i][(x+2)%10];
                ll a = cards[0][cards[0].size()-1];
                ll b = cards[1][cards[1].size()-1];
                if(x>=8){
                    add+=a+b+max(a,b);
                }
                else{
                    add+=a+b;
                }
                dp[i+1][x]=  max(dp[i+1][x],add);
            }
            if(cards[1].size()>=1){
                ll add = dp[i][(x+1)%10];
                ll a = cards[1][cards[1].size()-1];
                if(x>=9){
                    add+=a;
                    add+=a;
                }
                else{
                    add+=a;
                }
                dp[i+1][x]= max(dp[i+1][x],add);
            }
            if(cards[2].size()>=1){
                ll add = dp[i][(x+1)%10];
                ll a = cards[2][cards[2].size()-1];
                if(x>=9){
                    add+=a;
                    add+=a;
                }
                else{
                add+=a;
                }
                dp[i+1][x] = max(dp[i+1][x],add);
            }
            dp[i+1][x] = max(dp[i+1][x],dp[i][x]);
        }
    }
    cout << dp[n][0] << endl;
}

int main(){
    cin >> n;
    
    solve();
}