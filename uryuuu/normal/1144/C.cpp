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
#define ll long long
int inf=0x3f3f3f3f;
using namespace std;
int n;
int a[201000],b[201000];
int aa=0,bb=0;
ll sum=0;
int aaa[200010],bbb[200010];
int main()
{
    int c;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c;
        if(a[c])
        {
            if(b[c])
            {
                cout<<"NO"<<endl;
                return 0;
            }
            else
            {
                b[c]++;
                bbb[bb++]=c;
            }
        }
        else
        {
            a[c]++;
            aaa[aa++]=c;
        }
    }
    sort(aaa,aaa+aa);
    sort(bbb,bbb+bb);
    cout<<"YES"<<endl;
    cout<<bb<<endl;
    for(int i=0;i<bb;i++)
        cout<<bbb[i]<<' ';
    cout<<endl;
    cout<<aa<<endl;
    for(int i=aa-1;i>=0;i--)
        cout<<aaa[i]<<' ';
    cout<<endl;
    return 0;
}