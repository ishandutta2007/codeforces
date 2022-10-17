
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
typedef  long long ll;

int cnt[3];
vector<int> ans;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(n--) {int tmp;cin>>tmp;cnt[tmp]++;}
    if(cnt[1]&&cnt[2]) cnt[1]--,cnt[2]--,ans.push_back(2),ans.push_back(1);
    while(cnt[2]) ans.push_back(2),cnt[2]--;
    while(cnt[1]) ans.push_back(1),cnt[1]--;
    for(int i:ans) cout<<i<<" ";
}