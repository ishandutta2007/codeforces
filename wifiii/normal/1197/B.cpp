#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
const int mod = 1e9+7;

int a[200005];
int main()
{
    int n;
    cin>>n;
    ii cin>>a[i];
    int mi=1,mx=-1;
    ii if(mx<a[i]) mx=a[i],mi=i;
    int l=mi-1,r=mi+1,p=mx;
    while(l>=1 && r<=n)
    {
        if(a[l]>p || a[r]>p) {cout<<"NO"<<endl;return 0;}
        if(a[l] > a[r]) p=a[l],l--;
        else p=a[r],r++;
    }
    while(l>=1)
    {
        if(a[l]>p) {cout<<"NO"<<endl;return 0;}
        else p=a[l],l--;
    }
    while(r<=n)
    {
        if(a[r]>p) {cout<<"NO"<<endl;return 0;}
        else p=a[r],r++;
    }
    puts("YES");
}