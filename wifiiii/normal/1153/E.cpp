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
#define pb push_back
vector<int> x,y;
int main()
{
    int n;
    cin>>n;
    int last = 0;
    for(int i=1;i<=n;++i)
    {
        cout << "? " << 1 << " " << 1 << " " << i << " " << n << endl;
        int ret;
        cin >> ret;
        cout.flush();
        if((ret-last) % 2)
        {
            x.pb(i);
        }
        last = ret;
    }
    last = 0;
    for(int i=1;i<=n;++i)
    {
        cout << "? " << 1 << " " << 1 << " " << n << " " << i << endl;
        int ret;
        cin >> ret;
        cout.flush();
        if((ret-last) % 2 )
        {
            y.pb(i);
        }
        last = ret;
    }
    if(x.size()==2 && y.size()==2)
    {
        cout << "? " << x[0] << " " << y[0] << " " << x[0] << " " << y[0] << endl;
        int ret;
        cin>>ret;
        cout.flush();
        if(ret % 2)
        {
            cout << "! " << x[0] << " " << y[0] << " " << x[1] << " " << y[1] << endl;
            cout << "! " << x[1] << " " << y[0] << " " << x[0] << " " << y[1] << endl;
        }
        else
        {
            cout << "! " << x[1] << " " << y[0] << " " << x[0] << " " << y[1] << endl;
            cout << "! " << x[0] << " " << y[0] << " " << x[1] << " " << y[1] << endl;
        }
    }
    else if(!x.size())
    {
        int y1=y[0],y2=y[1];
        int qy = min(y1, y2);
        int lo = 1, hi = n;
        while(lo < hi)
        {
            int mid = (lo + hi) / 2;
            cout << "? " << 1 << " " << 1 << " " << mid << " " << qy << endl;
            int ret;
            cin>>ret;
            cout.flush();
            if(ret%2) hi=mid;
            else lo=mid+1;
        }
        cout << "! " << lo << " " << y1 << " " << lo << " " << y2 << endl;
    }
    else if(!y.size())
    {
        int x1=x[0],x2=x[1];
        int qx = min(x1,x2);
        int lo = 1, hi = n;
        while(lo<hi)
        {
            int mid = (lo+hi)/2;
            cout << "? " << 1 << " " << 1 << " " << qx << " " << mid << endl;
            int ret;
            cin >> ret;
            cout.flush();
            if(ret%2) hi=mid;
            else lo=mid+1;
        }
        cout << "! " << x1 << " " << lo << " " << x2 << " " << lo << endl;
    }
    else
    {
        while(1);
    }
}