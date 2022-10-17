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

int a[40];
int b[100005];
int main()
{
    int n;
    cin>>n;
    ii cin>>b[i];
    ii {
        for(int j=0;j<31;++j) if(b[i]&(1<<j)) a[j]++;
    }
    int mx = 0, mi = 1;
    ii
    {
        int tmp=0;
        for(int j=0;j<31;++j) if((a[j]==1) && (b[i]&(1<<j))) tmp|=1<<j;
        if(tmp > mx)
        {
            mx = tmp;
            mi = i;
        }
    }
    swap(b[1], b[mi]);
    ii cout<<b[i]<<" ";cout<<endl;
}