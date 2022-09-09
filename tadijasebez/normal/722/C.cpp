#include <stdio.h>
#include <map>
using namespace std;
#define ll long long
const int N=100050;
const int M=4*N;
int max(int a, int b){ return a>b?a:b;}
int x[M],ls[M],rs[M],clock,root;
void Set(int &c, int ss, int se, int qs, int qe, int val)
{
	if(ss>qe || qs>se) return;
	if(!c) c=++clock;
	if(qs<=ss && qe>=se){x[c]=max(x[c],val);return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
}
void Set(int &c, int qs, int qe, int val){Set(c,1,N,qs,qe,val);}
int A;
void Get(int c, int ss, int se, int qi)
{
	A=max(A,x[c]);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Get(ls[c],ss,mid,qi);
	else Get(rs[c],mid+1,se,qi);
}
int Get(int c, int qi){A=0;Get(c,1,N,qi);return A;}
int l[M],r[M],cnt;
map<ll,int> C;
ll S[N];
void Print(){
	if(C.empty()) printf("0\n");
	else printf("%lld\n",C.rbegin()->first);
}
int main()
{
	int n,x,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&x),S[i]=S[i-1]+x;
	C[S[n]]++;
	l[1]=1;
	r[1]=n;
	Set(root,1,n,1);
	cnt=1;
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		int y=Get(root,x);
		ll tmp=S[r[y]]-S[l[y]-1];
		C[tmp]--;
		if(!C[tmp]) C.erase(tmp);
		if(x>l[y])
		{
			cnt++;
			l[cnt]=l[y];
			r[cnt]=x-1;
			Set(root,l[cnt],r[cnt],cnt);
			tmp=S[r[cnt]]-S[l[cnt]-1];
			C[tmp]++;
		}
		if(x<r[y])
		{
			cnt++;
			l[cnt]=x+1;
			r[cnt]=r[y];
			Set(root,l[cnt],r[cnt],cnt);
			tmp=S[r[cnt]]-S[l[cnt]-1];
			C[tmp]++;
		}
		Print();
	}
	return 0;
}