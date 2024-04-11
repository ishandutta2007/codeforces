#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
int arr[60];

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int ans=0;
	for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    for(int i=0;i<n;i++)
    {
        if(arr[i]>=arr[k-1]&&arr[i]>0)
            ans++;
    }
    cout<<ans<<endl;
	return 0;
}