#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=200050;
struct Segment
{
	int l,r;
	inline bool operator < (const Segment &b) const
	{
		return r<b.r;
	}
	Segment(){}
	Segment(int a, int b){l=a,r=b;}
} A[N];
int main()
{
	int n,x,h,i;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i %i",&x,&h),A[i]=Segment(x-h,x+h);
	sort(A,A+n);
	int j=0,ans=1;
	for(i=1;i<n;i++) if(A[i].l>=A[j].r) j=i,ans++;
	printf("%i\n",ans);
	return 0;
}