#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
 
  int n;
int ans=0;
  //cin >> a >> k;

cin>>n;

std::vector<int> d(n);
std::vector<int> g(n);
std::vector<int> f(100001, 0);
std::string s;
//int ans=0;
for(int i=0;i<n;i++){
    int x,y;
    cin >>x>>y;
    d[i]=x;
    g[i]=y;
    //xp;
    f[x]++;

}

for(int i=0;i<n;i++){
  
    int dom=(n-1)+f[g[i]];
    int go=n-1-f[g[i]];
    cout<<dom<<" "<<go<<endl;

}

  //cout << ans;
  //cout<<coll;
 //cout << s << s.length() << s[2];
  return 0;
}