#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
//random_device rng;
//mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[300005][9];
int b[3005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    ii for(int j=0;j<m;++j) cin>>a[i][j];
    int lo=0,hi=1e9;
    while(lo<hi)
    {
        memset(b,0,sizeof(b));
        int mid=(1+lo+hi)/2;
        vector<int> tmp;
        for(int i=1;i<=n;++i)
        {
            int bits = 0;
            for(int j=0;j<m;++j) {
                if(a[i][j] >= mid) bits ^= 1<<j;
            }
            b[bits]++;
            tmp.push_back(bits);
        }
        for(int i=0;i<m;++i) {
            for(int j=0;j<1<<m;++j) {
                if(j&(1<<i)) b[j^(1<<i)]+=b[j];
            }
        }
        int ok = 0;
        for(int i : tmp) {
            if(b[i^((1<<m)-1)]) {ok = 1;break;}
        }
        if(ok) lo = mid;
        else hi = mid - 1;
    }
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;++i)
    {
        int bits = 0;
        for(int j=0;j<m;++j) {
            if(a[i][j] >= lo) bits ^= 1<<j;
        }
        b[bits] = i;
    }
    for(int i=0;i<1<<m;++i) {
        if(!b[i]) continue;
        int inv = i^((1<<m)-1);
        for(int j=0;j<1<<m;++j) {
            if(!b[j]) continue;
            if((inv&j)==inv) {
                cout << b[i] << " " << b[j] << endl;
                return 0;
            }
        }
    }
    
}