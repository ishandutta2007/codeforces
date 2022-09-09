#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300050;
const int M=2*N;
int a[N],mx[N],mn[N],rct[M],n;
ll ans;
void Solve(int l, int r)
{
	if(l>r) return;
	if(l==r){ ans++;return;}
	int mid=l+r>>1,L,R;
	Solve(l,mid);
	Solve(mid+1,r);
	mn[mid]=mx[mid]=a[mid];
	for(int i=mid-1;i>=l;i--) mn[i]=min(mn[i+1],a[i]),mx[i]=max(mx[i+1],a[i]);
	mn[mid+1]=mx[mid+1]=a[mid+1];
	for(int i=mid+2;i<=r;i++) mn[i]=min(mn[i-1],a[i]),mx[i]=max(mx[i-1],a[i]);
	ll pans=ans;
	//Case 1
	for(int i=l;i<=mid;i++)
	{
		int sz=mx[i]-mn[i]+1-mid+i-1;
		if(mid+sz<=r && mid+sz>mid && mx[mid+sz]<mx[i] && mn[mid+sz]>mn[i])
		{
			//if(l==1 && r==n) printf("Case 1: cool %i %i %i\n",i,sz,mid+sz);
			ans++;
		}
	}
	//if(l==1 && r==n) printf("Case1:%lld\n",ans-pans);
	//if(l==6 && r==7) printf("Case 1:%lld\n",ans-pans);
	//Case 2
	for(int i=mid+1;i<=r;i++)
	{
		int sz=mx[i]-mn[i]+1-i+mid;
		if(mid-sz+1>=l && mid-sz+1<=mid && mx[mid-sz+1]<mx[i] && mn[mid-sz+1]>mn[i]) ans++;
	}
	//if(l==1 && r==n) printf("Case2:%lld\n",ans-pans);
	//if(l==6 && r==7) printf("Case 2:%lld\n",ans-pans);
	//Case 3
	for(int i=l;i<=r;i++) rct[mn[i]+i]=rct[mx[i]+i]=0;
	L=r+1,R=r;
	for(int i=l;i<=mid;i++)
	{
		while(R<r && mx[R+1]<mx[i]) R++,rct[mn[R]+R]++;
		while(R>mid && mx[R]>mx[i]) rct[mn[R]+R]--,R--;
		while(L<=r && mn[L]>mn[i]) rct[mn[L]+L]--,L++;
		while(L>mid+1 && mn[L-1]<mn[i]) L--,rct[mn[L]+L]++;
		if(R>=L) ans+=rct[mx[i]+i];
		//if(l==1 && r==n) printf("Case 3:%i (%i %i)\n",i,L,R);
	}
	//if(l==1 && r==n) printf("Case3:%lld\n",ans-pans);
	//if(l==6 && r==7) printf("Case 3:%lld %i %i\n",ans-pans,mx[l]+l,mn[r]+r);
	//Case 4
	for(int i=l;i<=r;i++) rct[mn[i]-i+N]=rct[mx[i]-i+N]=0;
	R=mid,L=mid+1;
	for(int i=l;i<=mid;i++)
	{
		while(R<r && mn[R+1]>mn[i]) R++,rct[mx[R]-R+N]++;
		while(R>mid && mn[R]<mn[i]) rct[mx[R]-R+N]--,R--;
		while(L<=r && mx[L]<mx[i]) rct[mx[L]-L+N]--,L++;
		while(L>mid+1 && mx[L-1]>mx[i]) L--,rct[mx[L]-L+N]++;
		if(R>=L) ans+=rct[mn[i]-i+N];
		//if(l==1 && r==n) printf("Case 4:%i (%i %i)\n",i,L,R);
	}
	//if(l==6 && r==7) printf("Case 4:%lld\n",ans-pans);
	//printf("(%i %i) (%i %i) = %lld\n",l,mid,mid+1,r,ans-pans);
}
ll bsol;
void BruteForce()
{
	bsol=0;
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j++)
	{
		int ma=a[i],mi=a[i];
		for(int k=i;k<=j;k++) ma=max(ma,a[k]),mi=min(mi,a[k]);
		if(ma-mi==j-i) bsol++;
	}
}
void Solve(){ ans=0;Solve(1,n);}
void Test()
{
	srand(time(0));
	for(int i=1;i<=1000;i++)
	{
		n=rand()%10+1;
		for(int j=1;j<=n;j++) a[j]=j;
		random_shuffle(a+1,a+1+n);
		Solve();
		BruteForce();
		if(ans!=bsol)
		{
			printf("%i\n",n);
			for(int j=1;j<=n;j++) printf("%i ",a[j]);
			printf("\n");
			printf("Solve:%lld, BruteForce:%lld\n",ans,bsol);
			return;
		}
	}
	printf("OK\n");
}
int main()
{
	bool test=0;
	if(test)
	{
		Test();
		return 0;
	}
	vector<pair<int,int> > ps;
	int i;
	scanf("%i",&n);ps.resize(n);
	for(i=0;i<n;i++) scanf("%i %i",&ps[i].first,&ps[i].second);
	sort(ps.begin(),ps.end());
	for(i=0;i<n;i++) a[i+1]=ps[i].second;
	Solve(1,n);
	printf("%lld\n",ans);
	return 0;
}