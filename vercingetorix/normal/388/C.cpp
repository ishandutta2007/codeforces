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
int m,n,k;
int si=0, gy=0;

cin >> n;
vi sp;
for(int i=0; i<n;i++){
    int s,x;
    cin>>s;
    if((s%2)==0){
        for(int j=0;j<s/2;j++){
            cin>>x;
            si+=x;
        }
        for(int j=0;j<s/2;j++){
            cin>>x;
            gy+=x;
        }
    }
    else{
        for(int j=0;j<s/2;j++){
            cin>>x;
            si+=x;
        }
        cin>>x;
        sp.pb(x);
        for(int j=0;j<s/2;j++){
            cin>>x;
            gy+=x;
        }
    }
}
std::sort(sp.begin(), sp.end());
std::reverse(sp.begin(), sp.end());
for(int i=0; i<sp.size();i++){
    if(i%2==0) si+=sp[i];
    else gy+=sp[i];
}
cout<<si<<" "<<gy;


//cout<<ans;
return 0;


}