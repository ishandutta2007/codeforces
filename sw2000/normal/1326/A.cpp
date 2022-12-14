#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int maxn=2e5+10;
const ll mod=998244353;

int main()
{
//    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;scanf("%d",&a);
        if(a==1)puts("-1");
        else
        {
            printf("2");
            for(int i=0;i<a-1;i++)printf("3");
            puts("");
        }
    }
	return 0;
}