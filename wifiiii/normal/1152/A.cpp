
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
using namespace std;
typedef long long ll;
int cnt1[3], cnt2[3];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        int tmp;
        cin>>tmp;
        cnt1[tmp%2]++;
    }
    for(int i=1;i<=m;++i)
    {
        int tmp;
        cin>>tmp;
        cnt2[tmp%2]++;
    }
    cout << min(cnt1[0],cnt2[1]) + min(cnt1[1], cnt2[0]) << endl;
}