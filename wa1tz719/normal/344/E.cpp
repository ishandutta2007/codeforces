#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
long long a[100005],b[100005];
int n,m;
bool ok(long long mid)
{
		int i1, i2;
		i1 = 0;
		i2 = 0;
		bool oks=true;
		while(i1<n && i2<m) {
			long long nowh =  a[i1];
			if (nowh - mid > b[i2]) {
				oks = false;
				break;
			}
			if (nowh + mid < b[i2]) {
				i1 ++;
				continue;
			}
			long long right;
			if (nowh <= b[i2]) {
				right = nowh + mid;
			}
			else {
				long long t1;
				t1 = nowh - b[i2];
				right = max(  mid - t1 * 2 + nowh ,  (mid-t1) / 2 + nowh );
			}
			while(i2<m && b[i2] <= right) i2++;
			i1++;
		}
		if (i2!=m) oks = false;
		return oks;
}
long long get_answer()
{
    long long l=0,r=1000000000000005ll;
    for (;l<=r;)
    {
        long long mid=(l+r)/2; 
        if (ok(mid)) r=mid-1; else l=mid+1;
    }
    return l;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cin>>n>>m;
    int i;
    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (i=0;i<m;i++)
    {
        cin>>b[i];
    }
    cout<<get_answer();
    return 0;
}