#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
using namespace std;
int a[200005];
stack<int>s;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int aa;
        cin>>aa;
        if(s.empty()||(s.top()-aa)%2)
            s.push(aa);
        else
            s.pop();
    }
    if(s.size()<=1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}