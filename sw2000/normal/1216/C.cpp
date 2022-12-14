#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=3e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

int a[3][4];

bool cover(int id)
{
    if(a[id][0]<=a[0][0]&&a[id][1]<=a[0][1]&&a[0][2]<=a[id][2]&&a[0][3]<=a[id][3])return true;
    if(a[id][0]<=a[0][0]&&a[id][1]<=a[0][1]&&a[0][2]<=a[id][2])a[0][1]=max(a[0][1],a[id][3]);
    if(a[id][0]<=a[0][0]&&a[id][1]<=a[0][1]&&a[0][3]<=a[id][3])a[0][0]=max(a[0][0],a[id][2]);
    if(a[id][0]<=a[0][0]&&a[0][2]<=a[id][2]&&a[0][3]<=a[id][3])a[0][3]=min(a[0][3],a[id][1]);
    if(a[id][1]<=a[0][1]&&a[0][2]<=a[id][2]&&a[0][3]<=a[id][3])a[0][2]=min(a[0][2],a[id][0]);
    return false;
}

int main()
{
	for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)cin>>a[i][j];
    }
    if(cover(1))
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(cover(2))cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

	return 0;
}