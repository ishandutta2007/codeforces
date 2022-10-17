
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
const int maxn = 2e5+5;

int a[maxn];
string ans;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    int i = 1, j = n;
    int last = -1;
    while(i<=j)
    {
        if(i==j)
        {
            if(a[i] > last) ans+="L";
            break;
        }
        else if(a[i] != a[j])
        {
            if(a[i] < a[j] && a[i] > last) last = a[i], ans+="L",i++;
            else if(a[i] > a[j] && a[j] > last) last = a[j], ans+="R",j--;
            else if(a[i] < a[j] && a[j] > last) last = a[j], ans+="R",j--;
            else if(a[i] > a[j] && a[i] > last) last = a[i], ans+="L",i++;
            else break;
        }
        else
        {
            int cnt1 = 0, cnt2 = 0;
            for(int k=i;k<=j;++k) if(a[k] > a[k-1]) cnt1++;
            for(int k=j;k>=i;--k) if(a[k] > a[k+1]) cnt2++;
            if(cnt1 > cnt2) for(int k=i;k<=j;++k) if(a[k] > a[k-1]) ans+="L"; else break;
            else for(int k=j;k>=i;--k) if(a[k] > a[k+1]) ans+="R";else break;
            break;
        }
    }
    cout << ans.size() << endl;
    cout << ans << endl;
}