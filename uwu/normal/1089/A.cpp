#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=201;

bool dp[4][4][MAXN][MAXN];
int ba[4][4][MAXN][MAXN], bb[4][4][MAXN][MAXN];
vector<pair<int,int>> ans;

void build(){
    dp[0][0][0][0]=1;
    for (int A=0;A<=3;++A){
        for (int B=0;B<=3;++B){
            for (int a=0;a<=200;++a){
                for (int b=0;b<=200;++b){
                    int lim=(A+B==5?15:25);
                    for (int i=0;i<=lim-2;++i){
                        if (B!=3&&A>=1&&a>=lim&&b>=i){
                            if (dp[A-1][B][a-lim][b-i]){
                                dp[A][B][a][b]=1;
                                ba[A][B][a][b]=lim;
                                bb[A][B][a][b]=i;
                            }
                        }
                        if (A!=3&&B>=1&&a>=i&&b>=lim){
                            if (dp[A][B-1][a-i][b-lim]){
                                dp[A][B][a][b]=1;
                                ba[A][B][a][b]=i;
                                bb[A][B][a][b]=lim;
                            }
                        }
                    }
                    for (int i=lim+1;i<=200;++i){
                        if (B!=3&&A>=1&&a>=i&&b>=i-2){
                            if (dp[A-1][B][a-i][b-i+2]){
                                dp[A][B][a][b]=1;
                                ba[A][B][a][b]=i;
                                bb[A][B][a][b]=i-2;
                            }
                        }
                        if (A!=3&&B>=1&&a>=i-2&&b>=i){
                            if (dp[A][B-1][a-i+2][b-i]){
                                dp[A][B][a][b]=1;
                                ba[A][B][a][b]=i-2;
                                bb[A][B][a][b]=i;
                            }
                        }
                    }
                }
            }
        }
    }
}

void print(int A, int B, int a, int b){
    if (A==0&&B==0) return;
    int sa=ba[A][B][a][b], sb=bb[A][B][a][b];
    ans.push_back({sa,sb});
    print(A-(sa>sb),B-(sb>sa),a-sa,b-sb);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    build();
    int t; cin >> t;
    while (t--){
        int a, b; cin >> a >> b;
        if (dp[3][0][a][b]){
            cout << "3:0" << '\n';
            print(3,0,a,b);
        }
        else if (dp[3][1][a][b]){
            cout << "3:1" << '\n';
            print(3,1,a,b);
        }
        else if (dp[3][2][a][b]){
            cout << "3:2" << '\n';
            print(3,2,a,b);
        }
        else if (dp[2][3][a][b]){
            cout << "2:3" << '\n';
            print(2,3,a,b);
        }
        else if (dp[1][3][a][b]){
            cout << "1:3" << '\n';
            print(1,3,a,b);
        }
        else if (dp[0][3][a][b]){
            cout << "0:3" << '\n';
            print(0,3,a,b);
        }
        else{
            cout << "Impossible";
        }
        reverse(ans.begin(),ans.end());
        for (auto x:ans){
            cout << x.first << ":" << x.second << " ";
        }
        ans.clear();
        cout << '\n';
    }
}