#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, string>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int n,k,id,w;
int main()
{
	cin>>n>>k;
	for(int i=0;i<400;i++)
    {
        cout<<"? 1"<<endl;
        cin>>w;
    }
    if(n<=350)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<"? "<<i<<endl;
            cin>>w;
            if(w<k)
            {
                id=i;
                break;
            }
        }
    }
    else
    {
        for(int i=1;i<=10;i++)
        {
            cout<<"? "<<i<<endl;
            cin>>w;
            if(w<k)
            {
                id=i;
                break;
            }
        }
        int st=sqrt(n)-2;
        if(id==0)for(int i=1;i<=n;i+=st)
        {
            cout<<"? "<<i<<endl;
            cin>>w;
            if(w<k)
            {
                id=i;
                break;
            }
        }
    }

    int l=1,r=n/2;
    while(l!=r)
    {
        int mid=(l+r)/2,idd=id+mid,ww;
        if(idd>n)idd-=n;
        cout<<"? "<<idd<<endl;
        cin>>ww;
        if(ww>w)r=mid;
        else l=mid+1;
    }

    id+=r;
    if(id>n)id-=n;
    cout<<"! "<<id<<endl;
    return 0;
}