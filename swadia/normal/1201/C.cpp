#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n,k;
int a[MAXN];
int main()
{
	cin>>n>>k;
	RPT(i,0,n)
		scanf("%d",&a[i]);
	sort(a,a+n);
	a[n]=INF*2;
	int ptr=n/2;
	int num;
	int tmp=a[ptr];
	int cnt=0;
	while (1)
	{
		while (a[ptr+1]==tmp)
			ptr++;
		num=ptr-n/2+1;
		int add=min((k-cnt)/num,(a[ptr+1]-tmp));
		//WRT(add);
		cnt+=add*num;
		tmp+=add;
		if (add==0)
			break;
	}
	cout<<tmp;
	return ~~(0^_^0);
}