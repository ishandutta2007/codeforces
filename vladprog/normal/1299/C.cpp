#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e6+100;

int a[N];
int pref[N];

bool lt(int l1,int r1,int l2,int r2)
{
    int sum1=(pref[r1]-pref[l1-1])*(r2-l2+1);
    int sum2=(pref[r2]-pref[l2-1])*(r1-l1+1);
//    if(sum1<sum2)
//        cout<<l1<<".."<<r1<<" < "<<l2<<".."<<r2<<"\n";
//    if(sum1==sum2)
//        cout<<l1<<".."<<r1<<" = "<<l2<<".."<<r2<<"\n";
//    if(sum1>sum2)
//        cout<<l1<<".."<<r1<<" > "<<l2<<".."<<r2<<"\n";
    return sum1<sum2;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(15);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],
        pref[i]=pref[i-1]+a[i];
    vector<int> v{0};
    for(int i=1;i<=n;i++)
    {
        #define get(ind) v[v.size()+(ind)]
        while(v.size()>=2&&lt(get(-2)+1,i,get(-2)+1,get(-1)))
            v.pop_back();
        v.push_back(i);
    }
    v.erase(v.begin());
    int l=1;
    for(int r:v)
    {
        ld cur=accumulate(a+l,a+r+1,0ll);
        cur/=r-l+1;
        for(int i=l;i<=r;i++)
            cout<<cur<<"\n";
        l=r+1;
    }
}