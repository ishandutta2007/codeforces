
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <unordered_map>
using namespace std;
typedef long long ll;
int min(int a,int b,int c)
{
    a = abs(a), b = abs(b), c = abs(c);
    int ret = a;
    if(b<ret) ret = b;
    if(c<ret) ret = c;
    return ret;
}
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans = 1e9;
    for(int i=0;i<=n-4;++i)
    {
        int tmp = 0;
        tmp += min(s[i]-'A', 'A'+26-s[i]);
        tmp += min('C'-26-abs(s[i+1]), abs(s[i+1]-'C'), abs('C'+26-s[i+1]));
        tmp += min('T'-26-abs(s[i+2]), abs(s[i+2]-'T'), abs('T'+26-s[i+2]));
        tmp += min('G'-26-abs(s[i+3]), abs(s[i+3]-'G'), abs('G'+26-s[i+3]));
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}