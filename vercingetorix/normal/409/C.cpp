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
int a1,a2,a3,a4,a5;
cin >> a1 >> a2>>a3>>a4>>a5;
int x=min(a1,a2);
x=min(x,a3/2);
x=min(x,a4/7);
x=min(x,a5/4);
cout<<x;

//cout<<ans;
return 0;


}