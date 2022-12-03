#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
vector<long long> ans;
void get_ans(long long n,long long i)
{
    long long x=(n/i);
    x+=(0+n-i)*(n/i)/2;
    ans.push_back(x);
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int i;
    for (i=1;i*i<=n;i++)
    {
        if (n%i==0)
        {
            get_ans(n,i);
            if (n/i!=i)
            {
                get_ans(n,n/i);
            }
        }
    }
    sort(ans.begin(),ans.end());
    for (i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}