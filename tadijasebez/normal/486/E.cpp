#include <stdio.h>
const int N=100050;
const int M=2*N;
int max(int a, int b){ return a>b?a:b;}
int x[M],ls[M],rs[M],tsz,root;
void Init(){ for(int i=1;i<=tsz;i++) ls[i]=rs[i]=x[i]=0;root=tsz=0;}
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++tsz;
	x[c]=max(x[c],val);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se || qs>qe) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int cnt[N],dp1[N],dp2[N],a[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	Init();
	for(i=1;i<=n;i++) dp1[i]=Get(root,1,N,1,a[i]-1)+1,Set(root,1,N,a[i],dp1[i]);
	Init();
	for(i=n;i>=1;i--) dp2[i]=Get(root,1,N,a[i]+1,N)+1,Set(root,1,N,a[i],dp2[i]);
	int len=0;
	for(i=1;i<=n;i++) len=max(len,dp1[i]+dp2[i]);
	for(i=1;i<=n;i++) if(dp1[i]+dp2[i]==len) cnt[dp1[i]]++;
	for(i=1;i<=n;i++)
	{
		if(dp1[i]+dp2[i]!=len) printf("1");
		else if(cnt[dp1[i]]>1) printf("2");
		else printf("3");
	}
	printf("\n");
	return 0;
}