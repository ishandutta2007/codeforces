#include <stdio.h>
#include <set>
using namespace std;
#define ll long long
const int N=200050;
const int M=N*8;
int x[M],ls[M],rs[M],clock,root1,root2;
int max(int a, int b){ return a>b?a:b;}
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
int CH[N],CV[N];
set<int> H,V;
void Print()
{
	int a=*H.rbegin();
	int b=*V.rbegin();
	printf("%lld\n",(ll)(a)*(b));
}
int main()
{
	int n,m,q,i,x;
	char t;
	scanf("%i %i %i",&n,&m,&q);
	Set(root1,1,n,1);
	l[1]=1;r[1]=n;
	V.insert(n);
	CV[n]++;
	Set(root2,1,M,2);
	l[2]=1;r[2]=m;
	H.insert(m);
	CH[m]++;
	cnt=2;
	while(q--){
		scanf("\n%c %i",&t,&x);
		if(t=='V')
		{
			int y=Get(root1,x);
			int tmp=r[y]-l[y]+1;
			CV[tmp]--;
			if(!CV[tmp]) V.erase(tmp);
			cnt++;
			l[cnt]=l[y];
			r[cnt]=x;
			Set(root1,l[cnt],r[cnt],cnt);
			tmp=r[cnt]-l[cnt]+1;
			if(!CV[tmp]) V.insert(tmp);
			CV[tmp]++;
			if(r[y]>x)
			{
				cnt++;
				l[cnt]=x+1;
				r[cnt]=r[y];
				Set(root1,l[cnt],r[cnt],cnt);
				tmp=r[cnt]-l[cnt]+1;
				if(!CV[tmp]) V.insert(tmp);
				CV[tmp]++;
			}
		}
		else
		{
			int y=Get(root2,x);
			int tmp=r[y]-l[y]+1;
			CH[tmp]--;
			if(!CH[tmp]) H.erase(tmp);
			cnt++;
			l[cnt]=l[y];
			r[cnt]=x;
			Set(root2,l[cnt],r[cnt],cnt);
			tmp=r[cnt]-l[cnt]+1;
			if(!CH[tmp]) H.insert(tmp);
			CH[tmp]++;
			if(r[y]>x)
			{
				cnt++;
				l[cnt]=x+1;
				r[cnt]=r[y];
				Set(root2,l[cnt],r[cnt],cnt);
				tmp=r[cnt]-l[cnt]+1;
				if(!CH[tmp]) H.insert(tmp);
				CH[tmp]++;
			}
		}
		Print();
	}
	return 0;
}