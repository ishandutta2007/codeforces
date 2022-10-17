
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

int cal(int x)
{
    int ret = 0;
    while(x%2==0) x/=2,ret++;
    return ret;
}
int check(int x)
{
    x++;
    while(x%2==0) x/=2;
    if(x==1) return 1;
    return 0;
}
int main()
{
    int x;
    cin>>x;
    vector<int> ans;
    int cnt = 0;
    int f = 1;
    while(1)
    {
        if(check(x)) break;
        if(!f) x++,cnt++;
        else
        {
            int tmp = cal(x);
            ans.push_back(tmp);
            x ^= (1<<tmp)-1;
        }
        f = 1 - f;
    }
    cout << cnt + ans.size() << endl;
    if(ans.size())
    {
        for(int i:ans) cout<<i<<" ";
        cout<<endl;
    }
}