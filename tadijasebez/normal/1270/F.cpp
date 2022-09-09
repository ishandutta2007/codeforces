#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int S=200;
const int N=200050;
char s[N];
int sum[N],n;
ll ans;
void Solve(int k)
{
	sum[0]=0;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(s[i]=='0'?1:-k);
	sort(sum,sum+1+n);
	for(int i=0,j=0;i<=n;i++)
	{
		j++;
		if(i==n || sum[i]!=sum[i+1])
		{
			ans+=(ll)j*(j-1)/2;
			j=0;
		}
	}
}
int pre[N],pos[N],nxt,ooo[N];
int main()
{
    vector<int> one;
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++) ooo[i]=s[i]=='0'?0:ooo[i-1]+1,ans+=ooo[i];
	for(int i=1;i<S;i++) Solve(i);
	//printf("ans: %lld :D\n",ans);
	for(int i=1;i<=n;i++) pre[i]=s[i]=='0'?pre[i-1]+1:0;
	for(int i=n;i>=1;i--) pos[i]=s[i]=='0'?pos[i+1]+1:0;
	for(int i=1;i<=n;i++) if(s[i]=='1') one.pb(i);
	for(int l=1;l<=n;l++)
	{
		while(nxt<one.size() && one[nxt]<l) nxt++;
		for(int ptr=nxt;ptr<one.size();ptr++)
		{
			int r=one[ptr];
			int sz=pos[r+1];
			int cnt=ptr-nxt+1;
			ll mnsz=(ll)(S+1)*cnt;
			if(mnsz>n-l+1) break;
			mnsz=max(mnsz,(ll)one[ptr]-l+1);
			if(mnsz%cnt!=0) mnsz+=cnt-(mnsz%cnt);
			ll mxsz=one[ptr]-l+1+sz;
			if(mxsz>=mnsz) ans+=(mxsz-mnsz+1+cnt-1)/cnt;
		}
	}
	printf("%lld\n",ans);
	/*for(int i=0;i<one.size();i++)
	{
		int lim=min(i+S,(int)one.size());
		for(int j=i;j<lim;j++)
		{
			int cnt=j-i+1;
			int sz=one[j]-one[i]+1;
			int L=pre[one[i]-1];
			int R=pos[one[j]+1];
            int LB=L/cnt;
            int RB=R/cnt;
            ans+=(ll)L*RB;
            L%=cnt;
            R%=cnt;
            sz%=cnt;
            sz=(cnt-sz)%cnt;
            int xr=(sz-L+cnt)%cnt;
            int dod=min(L+1,R-xr+1);
            L-=dod;
            ans+=dod;
            int xl=sz;
            dod=max(0,min(L-xl+1,xr));
            ans+=dod;
		}
	}*/
	return 0;
}