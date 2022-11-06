#include<stdio.h>
int MOD = 1000000007;
int in[20];
int dp[20][20], dpall[20][20], all[20][20];
int P6(int x)
{
    int ans = 1;
    for(int i=1; i<=6; i++) ans = 1ll*ans*(x-i+1)%MOD;
    return ans;
}
int main()
{
    int a, b, c=0;
    int i, j, k;
    scanf("%d", &a);
    b = a;
    while(b) {in[++c] = b%10; b/=10;}
    if(in[1] < 4)
    {
        dp[1][0] = in[1]+1;
    }
    else if(in[1] < 7)
    {
        dp[1][0] = in[1];
        dp[1][1] = 1;
    }
    else
    {
        dp[1][0] = in[1] - 1;
        dp[1][1] = 2;
    }
    dpall[1][0] = 8;
    dpall[1][1] = 2;
    for(i=2; i<=c; i++)
    {
        for(j=0; j<in[i]; j++)
        {
            for(k=0; k<=i; k++)
            {
                dp[i][k+(((j==4)||(j==7))?1:0)] += dpall[i-1][k];
                dp[i][k+(((j==4)||(j==7))?1:0)]%=MOD;
            }
        }
        for(k=0; k<=i; k++)
        {
            dp[i][k+(((in[i]==4)||(in[i]==7))?1:0)] += dp[i-1][k];
            dp[i][k+(((in[i]==4)||(in[i]==7))?1:0)]%=MOD;
        }
        for(j=0; j<10; j++)
        {
            for(k=0; k<=i; k++)
            {
                dpall[i][k+(((j==4)||(j==7))?1:0)] += dpall[i-1][k];
                dpall[i][k+(((j==4)||(j==7))?1:0)]%=MOD;
            }
        }
    }
    dp[c][0]--;
//  printf("^:%d %d %d %d %d %d\n", dp[c][0], dp[c][1], dp[c][2], dpall[c-1][0], dpall[c-1][1], dpall[c-1][2]);
    int ans = 0;
    for(int i1=0; i1<=c; i1++)
    {
        int sum = dp[c][i1];
        dp[c][i1] --;
        for(int i2=0; i2<=c; i2++)
        {
            int tmp = sum;
            sum = 1ll*sum*dp[c][i2]%MOD;
            dp[c][i2]--;
            for(int i3=0; i3<=c; i3++)
            {
                int tmp = sum;
                sum = 1ll*sum*dp[c][i3]%MOD;
                dp[c][i3]--;
                for(int i4=0; i4<=c; i4++)
                {
                    int tmp = sum;
                    sum = 1ll*sum*dp[c][i4]%MOD;
                    dp[c][i4]--;
                    for(int i5=0; i5<=c; i5++)
                    {
                        int tmp = sum;
                        sum = 1ll*sum*dp[c][i5]%MOD;
                        dp[c][i5]--;
                        for(int i6=0; i6<=c; i6++)
                        {
                            int tmp = sum;
                            sum = 1ll*sum*dp[c][i6]%MOD;
                            dp[c][i6]--;
                            for(int i7=i1+i2+i3+i4+i5+i6+1; i7<=c; i7++) ans = (ans + 1ll*sum*dp[c][i7])%MOD;
                            dp[c][i6]++;
                            sum = tmp;
                        }
                        dp[c][i5]++;
                        sum = tmp;
                    }
                    dp[c][i4]++;
                    sum = tmp;
                }
                dp[c][i3]++;
                sum = tmp;
            }
            dp[c][i2]++;
            sum = tmp;
        }
        dp[c][i1] ++;
    }
    printf("%d", ans);
    return 0;
}