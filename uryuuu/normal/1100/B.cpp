#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
int inf=0x3f3f3f3f;
using namespace std;
int n,m;
int a[100010],book[100010];
int main()
{
    int s=0;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
        if(book[a[i]]==0)
            s++;
        book[a[i]]++;
        if(s==n)
        {
            cout<<1;
            s=0;
            for(int j=1;j<=n;j++)
            {
                book[j]--;
                if(book[j])
                    s++;
            }
        }
        else
            cout<<0;
    }
    cout<<endl;
    return 0;
}