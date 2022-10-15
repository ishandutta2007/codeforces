#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007ll
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int64_t n;
    cin >> n;
    int64_t X[n];
    for(int64_t i=0;i<n;i++)
        cin>>X[i];
    sort(X, X + n);
    int64_t sum[n];
    sum[0]=X[0]%MOD;
    for(int64_t i=1;i<n;i++)
        sum[i]=(sum[i-1]*2+X[i])%MOD;
    int64_t ats=0;
    int64_t P_2[n];
    P_2[0]=1;
    for(int64_t i=1;i<n;i++)
        P_2[i]=(P_2[i-1] * 2)%MOD;
    for(int64_t i=1;i<n;i++)
    {
        ats=(ats+((X[i]%MOD)*((P_2[i]-1+MOD)%MOD))%MOD-sum[i-1]+MOD)%MOD;
    }
    cout<<ats;
    return 0;
}