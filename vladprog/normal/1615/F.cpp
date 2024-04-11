#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2010,MOD=1e9+7;

signed cnt[N][N][3][3],sum[N][N][3][3];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        s="0"+s;
        t="0"+t;
        for(int i=1;i<=n;i+=2)
        {
            if(s[i]!='?')
                s[i]^=1;
            if(t[i]!='?')
                t[i]^=1;
        }
//        cout<<s<<"\n"<<t<<"\n";
        cnt[0][0][0][0]=
        cnt[0][0][2][0]=
        cnt[0][0][0][2]=
        cnt[0][0][2][2]=1;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
            {
                if(i==0&&j==0)
                    continue;
                sum[i][j][0][0]=
                sum[i][j][0][1]=
                sum[i][j][1][0]=
                sum[i][j][1][1]=
                cnt[i][j][0][0]=
                cnt[i][j][0][1]=
                cnt[i][j][1][0]=
                cnt[i][j][1][1]=0;
                if(s[i]!='1'&&t[j]!='1')
                    cnt[i][j][0][0]=cnt[max(0ll,i-1)][max(0ll,j-1)][2][2],
                    sum[i][j][0][0]=sum[max(0ll,i-1)][max(0ll,j-1)][2][2];
                if(i>0&&j>0&&s[i]!='0'&&t[j]!='0')
                    cnt[i][j][1][1]=cnt[i-1][j-1][2][2],
                    sum[i][j][1][1]=(sum[i-1][j-1][2][2]+cnt[i-1][j-1][2][2]*abs(i-j))%MOD;
                if(j>0&&s[i]!='0'&&t[j]!='1')
                    cnt[i][j][1][0]=cnt[i][j-1][1][2],
                    sum[i][j][1][0]=sum[i][j-1][1][2];
                if(i>0&&s[i]!='1'&&t[j]!='0')
                    cnt[i][j][0][1]=cnt[i-1][j][2][1],
                    sum[i][j][0][1]=sum[i-1][j][2][1];
                cnt[i][j][0][2]=(cnt[i][j][0][0]+cnt[i][j][0][1])%MOD;
                cnt[i][j][2][0]=(cnt[i][j][0][0]+cnt[i][j][1][0])%MOD;
                cnt[i][j][1][2]=(cnt[i][j][1][0]+cnt[i][j][1][1])%MOD;
                cnt[i][j][2][1]=(cnt[i][j][0][1]+cnt[i][j][1][1])%MOD;
                cnt[i][j][2][2]=(0ll+cnt[i][j][0][0]+cnt[i][j][0][1]+cnt[i][j][1][0]+cnt[i][j][1][1])%MOD;
                sum[i][j][0][2]=(sum[i][j][0][0]+sum[i][j][0][1])%MOD;
                sum[i][j][2][0]=(sum[i][j][0][0]+sum[i][j][1][0])%MOD;
                sum[i][j][1][2]=(sum[i][j][1][0]+sum[i][j][1][1])%MOD;
                sum[i][j][2][1]=(sum[i][j][0][1]+sum[i][j][1][1])%MOD;
                sum[i][j][2][2]=(0ll+sum[i][j][0][0]+sum[i][j][0][1]+sum[i][j][1][0]+sum[i][j][1][1])%MOD;
            }
//        for(int i=0;i<=n;i++,cout<<"\n")
//            for(int j=0;j<=n;j++)
//                cout<<cnt[i][j][2][2]<<" ";
//        for(int i=0;i<=n;i++,cout<<"\n")
//            for(int j=0;j<=n;j++)
//                cout<<sum[i][j][2][2]<<" ";
        cout<<sum[n][n][2][2]<<"\n";
    }
}