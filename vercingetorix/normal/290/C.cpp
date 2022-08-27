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
int tux, pur;
int foo=0;
int bar=0;
int baz=0;
int quz=0;
cin >> tux;
for(;tux>0; tux--){
    cin>>pur;
    foo+=pur;
    bar++;
    if(foo*quz>=bar*baz){
        baz=foo;
        quz=bar;
    }
}
printf("%.5f",(float)baz/(float)quz);

//cout<<ans;
return 0;


}