#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
int dp[101][1<<16];
int main() {
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    int val[55];
    val[1] = 0;
    map<int,int> num;
    num[2] = 0, num[3] = 1, num[5] = 2, num[7] = 3, num[11] = 4, num[13] = 5;
    num[17] = 6,num[19] = 7, num[23] = 8, num[29] = 9, num[31]=10, num[37]=11,num[41] = 12, num[43] = 13, num[47] = 14, num[53] = 15;
    for(int i=2;i<=53;i++) {
        int temp = i;
        val[i] = 0;
        for(int j=2;j<=53;j++) {
            if(temp%j==0) {
                while(temp%j==0) {
                    val[i]+=1<<num[j];
                    while(temp%j==0) temp/=j;
                }
            }
        }
        if(temp>1) val[i]+=1<<num[temp];
    }
    for(int i=0;i<1<<16;i++) dp[0][i] = 0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<1<<16;j++) dp[i][j] = 1000000000;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<1<<16;j++) {
            for(int put=1;put<=53;put++) {
                int msk = val[put];
                if((msk&j)==0) {
                    dp[i][j] = min(dp[i][j],dp[i-1][j|msk]+abs(a[i-1]-put));
                }
            }
        }
    }
    int b[n];
    int currmsk = 0;
    for(int i=n;i>=1;i--) {
        bool found = false;
        for(int put=1;put<=53 && !found;put++) {
            int msk = val[put];
            if((msk&currmsk)==0) {
                if(dp[i-1][currmsk|msk]+abs(a[i-1]-put)==dp[i][currmsk]) {
                    found = true;
                    b[i-1] = put;
                    currmsk = currmsk|msk;
                }
            }
        }
    }
    for(int i=0;i<n;i++) cout << b[i] << endl;
}