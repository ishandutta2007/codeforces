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

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

int ans=0;
ll m,n,k,d;

cin >> n>>k>>d;
ll x=1;
for(int i=0;i<d;i++){
    x*=k;
    if(x>=n) break;
}
if(x<n){
    cout<<-1;
    return 0;
}
vi a(n+1);
for(int i=1;i<=n;i++) a[i]=i;
for(int i=0;i<d;i++){
    for(int j=1;j<=n;j++){
        cout<<(a[j]%k)+1<<" ";
        a[j]/=k;
    }
    cout<<endl;
}


//cout<<ans;
return 0;


}