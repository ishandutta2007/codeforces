#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=300050;
const int M=2*N;
int ls[M],rs[M],tsz,root;
ll lzy[M],mx[M];
void Add(int &c, int ss, int se, int qs, int qe, ll f)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(!c) c=++tsz;
	if(qs<=ss && qe>=se){ lzy[c]+=f;mx[c]+=f;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mx[c]=max(mx[ls[c]],mx[rs[c]])+lzy[c];
}
int L[N],R[N],c;
ll V[N];
int D[N],C[N];
int main()
{
	int n,i,a;
	scanf("%i %i",&n,&a);
	ll ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&D[i],&C[i]);
		ll dif=i==1?(ll)0:(ll)(D[i]-D[i-1])*(D[i]-D[i-1]);
		while(c && V[c]<dif)
		{
			Add(root,1,N,L[c],R[c],V[c]);
			c--;
		}
		Add(root,1,N,R[c]+1,i-1,-dif);
		c++;
		L[c]=R[c-1]+1;
		R[c]=i-1;
		V[c]=dif;
		Add(root,1,N,1,i,-C[i]);
		Add(root,1,N,1,i,a);
		ans=max(ans,mx[root]);
		//printf("->%i: %lld\n",i,mx[root]);
	}
	printf("%lld\n",ans);
	return 0;
}