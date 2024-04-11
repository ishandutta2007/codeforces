#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
ll mod=1000000007;

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

int ans=0;
int n,a,b,k;
cin>>n>>a>>b>>k;
if(a>b){
    b=n+1-b;
    a=n+1-a;
}
int sumk_fk[5001][2];
int fk[5001][2];
for(int i=0;i<b;i++) sumk_fk[i][0]=i;
for(int i=1;i<b;i++) fk[i][0]=1;
for(int i=1;i<=k;i++){
    sumk_fk[0][i%2]=0;
    int i1=(i+1)%2;
    ll sum=0;
    for(int j=1; j<b; j++){
        int fmin=max(2*j-b+1,1);
        int fmax=(b-1);
        ll curfk = (sumk_fk[fmax][i1] - sumk_fk[fmin-1][i1] - fk[j][i1])%mod;
        if(curfk<0) curfk=(curfk+mod)%mod;
        fk[j][i%2]=curfk;
        sum=(sum+curfk)%mod;
        sumk_fk[j][i%2]=sum;
    }
}
cout<<fk[a][k%2];
return 0;


}