#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int MN = 505, mod = 1e9+7;
int N, M, i, j, k, dp[2][MN][MN];
string s[MN];

int main(){
    for(scanf("%d%d",&N,&M),i=0;i<N;i++)
        cin >> s[i];
    if(s[0][0]!=s[N-1][M-1]) printf("0\n");
    else{
        dp[0][0][0]=1;
        for(i=0;i<(N+M-2)/2;i++){
            memset(dp[(i+1)&1],0,sizeof(dp[(i+1)&1]));
            for(j=0;j<=min(N-1,i);j++){
                for(k=0;k<=min(N-1,i);k++){
                    int a=i-j, b=i-k;
                    for(int ii=0;ii<2;ii++){
                        for(int jj=0;jj<2;jj++){
                            int ax=a+ii, ay=j+(!ii);
                            int bx=b+jj, by=k+(!jj);
                            if(ax>=M||ay>=N||bx>=M||by>=N) continue;
                            if(s[ay][ax]==s[N-by-1][M-bx-1]){
                                dp[(i+1)&1][ay][by]+=dp[i&1][j][k];
                                if(dp[(i+1)&1][ay][by]>=mod) dp[(i+1)&1][ay][by]-=mod;
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(j=0;j<=min(N-1,i);j++){
            ans += dp[i&1][j][N-j-1];
            if(ans>=mod) ans -= mod;
            if((N+M)%2&&N-j-2>=0) ans += dp[i&1][j][N-j-2];
            if(ans>=mod) ans -= mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}