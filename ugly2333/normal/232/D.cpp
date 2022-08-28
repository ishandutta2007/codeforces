//CF 
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 2e5+15;
const int Q = 20;
const int W = 333;
const int inf = 2e9+N;
const int B = 131;
const int mod = 1e9+9;
int n,a[N],b[N];
int sab[N],rkb[N],lcp[N];
int nn,c[N+N],sac[N+N],rkc[N+N];
int hc[N+N],pwr[N+N],tl[N],tr[N];
int st[N][Q];
int m,l[N],r[N],len[N],ans[N],t[N];
pair<pair<int,int>,int> p[N+N];
int ql[N],qr[N],s[N];
vector<pair<pair<int,int>,int> > q[N];
int T[N+N];
int gethash(int L,int R){
	LL res;
	res=(LL)pwr[nn-R+L-1]*hc[R]%mod+mod;
	res-=(LL)pwr[nn]*hc[L-1]%mod;
	return res%mod;
}
void ad(int x){
	while(x<=N+n){
		T[x]++;
		x+=x&-x;
	}
}
int qu(int x){
	int res;
	res=0;
	while(x){
		res+=T[x];
		x-=x&-x;
	}
	return res;
}
int main()
{
	int i,j,x,y,z,cl,cr;
	//n=1e3;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		//a[i]=i/334+1;
		//cout<<a[i]<<' ';
		scanf("%d",a+i);
		if(i-1){
			b[i-1]=a[i]-a[i-1];
			c[i-1]=b[i-1];
			c[n+i-1]=-b[i-1];
			//cout<<b[i-1]<<' ';
		}
	}
	c[n]=-inf;
	//cout<<endl;
	
	for(i=1;i<n;i=i+1)
		p[i]=make_pair(make_pair(b[i],0),i);
	for(j=0;j<Q;j=j+1){
		x=1<<j;
		sort(p+1,p+n);
		for(i=1;i<n;i=i+1){
			rkb[p[i].second]=rkb[p[i-1].second];
			if(i==1||p[i].first!=p[i-1].first)
				rkb[p[i].second]++;
		}
		for(i=1;i<n;i=i+1){
			p[i]=make_pair(make_pair(rkb[i],0),i);
			if(i+x<n)
				p[i].first.second=rkb[i+x];
		}
	}
	for(i=1;i<n;i=i+1)
		sab[rkb[i]]=i;
	/*for(i=1;i<n;i=i+1)
		cout<<rkb[i]<<' ';
	cout<<endl;*/
	
	x=0;
	for(i=1;i<n;i=i+1){
		j=sab[rkb[i]-1];
		while(j+x<n&&i+x<n&&b[j+x]==b[i+x]){
			x++;
		}
		lcp[rkb[i]-1]=x;
		if(x)
			x--;
	}
	/*for(i=1;i<n;i=i+1)
		cout<<lcp[i]<<' ';
	cout<<endl;*/
	
	for(i=1;i<n-1;i=i+1)
		st[i][0]=lcp[i];
	x=1;
	for(j=1;j<Q;j=j+1){
		for(i=1;i<n-1;i=i+1){
			if(i+x>=n-1)
				st[i][j]=0;
			else
				st[i][j]=min(st[i][j-1],st[i+x][j-1]);
			//if(j<=2) cout<<st[i][j]<<' ';
		}
		//if(j<=2) cout<<endl;
		x<<=1;
	}
	
	nn=n+n;
	/*for(i=1;i<nn;i=i+1)
		cout<<c[i]<<' ';
	cout<<endl;*/
	for(i=1;i<nn;i=i+1)
		p[i]=make_pair(make_pair(c[i],0),i);
	for(j=0;j<Q;j=j+1){
		x=1<<j;
		sort(p+1,p+nn);
		for(i=1;i<nn;i=i+1){
			rkc[p[i].second]=rkc[p[i-1].second];
			if(i==1||p[i].first!=p[i-1].first)
				rkc[p[i].second]++;
		}
		for(i=1;i<nn;i=i+1){
			p[i]=make_pair(make_pair(rkc[i],0),i);
			if(i+x<nn)
				p[i].first.second=rkc[i+x];
		}
	}
	for(i=1;i<nn;i=i+1)
		sac[rkc[i]]=i;
	/*for(i=1;i<nn;i=i+1)
		cout<<sac[i]<<' ';
	cout<<endl;*/
	
	x=0;
	for(i=1;i<nn;i=i+1){
		j=sac[i];
		if(j==n)
			continue;
		if(j<n)
			x=j;
		else
			tl[j-n]=x;
	}
	x=0;
	for(i=nn-1;i>0;i=i-1){
		j=sac[i];
		if(j==n)
			continue;
		if(j<n)
			x=j;
		else
			tr[j-n]=x;
	}
	/*for(i=1;i<n;i=i+1)
		cout<<tr[i]<<' ';
	cout<<endl;*/
	
	scanf("%d",&m);
	for(i=1;i<=m;i=i+1){
		//l[i]=1,r[i]=3;
		scanf("%d%d",l+i,r+i);
		len[i]=r[i]-l[i];
		r[i]--;
		if(!len[i])
			ans[i]=n-1;
	}
	
	pwr[0]=1;
	hc[0]=0;
	for(i=1;i<=nn;i=i+1){
		pwr[i]=(LL)pwr[i-1]*B%mod;
		hc[i]=((LL)hc[i-1]*B+(LL)c[i]+(LL)mod*10)%mod;
	}
	//cout<<gethash(1,3)<<endl<<gethash(15,17)<<endl;
	//cout<<gethash(9,9)<<endl<<gethash(19,19)<<endl;
	
	for(i=1;i<=m;i=i+1){
		if(!len[i])
			continue;
		if(tl[l[i]]+len[i]<=n&&gethash(l[i]+n,r[i]+n)==gethash(tl[l[i]],tl[l[i]]+len[i]-1))
			t[i]=tl[l[i]];
		if(tr[l[i]]+len[i]<=n&&gethash(l[i]+n,r[i]+n)==gethash(tr[l[i]],tr[l[i]]+len[i]-1))
			t[i]=tr[l[i]];
	}
	/*for(i=1;i<=m;i=i+1)
		cout<<t[i]<<' ';
	cout<<endl;*/
	
	for(i=1;i<=m;i=i+1){
		if(!t[i])
			continue;
		ql[i]=rkb[t[i]];
		for(j=Q-1;j>=0;j=j-1){
			x=1<<j;
			if(ql[i]-x>0&&st[ql[i]-x][j]>=len[i])
				ql[i]-=x;
		}
		qr[i]=rkb[t[i]];
		for(j=Q-1;j>=0;j=j-1){
			x=1<<j;
			if(qr[i]+x<n&&st[qr[i]][j]>=len[i])
				qr[i]+=x;
		}
		//cout<<ql[i]<<' '<<qr[i]<<endl;
		if(l[i]-len[i]-1>0)
			q[l[i]-len[i]-1].push_back(make_pair(make_pair(ql[i],qr[i]),i));//,cout<<l[i]-len[i]<<endl;
		q[r[i]+1].push_back(make_pair(make_pair(ql[i],qr[i]),-i));
		q[n-len[i]].push_back(make_pair(make_pair(ql[i],qr[i]),i));
		//cout<<i<<' '<<ql[i]<<' '<<qr[i]<<' ';
		//cout<<l[i]-len[i]<<' '<<r[i]+1<<' '<<n-len[i]<<endl;
	}
	
	for(i=1;i<=n;i=i+1){
		if(i<n)
			ad(rkb[i]);
		for(j=0;j<q[i].size();j=j+1){
			y=qu(q[i][j].first.second)-qu(q[i][j].first.first-1);
			z=q[i][j].second;
			if(z>0)
				ans[z]+=y;
			else
				ans[-z]-=y;
		}
	}
	
	/*if(n==100000){
		for(i=1;i<=m;i=i+1)
			cout<<l[i]<<r[i]<<endl;
	}*/
	for(i=1;i<=m;i=i+1)
		cout<<ans[i]<<endl;
	return 0;
}
/*
10
2 3 4 5 6 5 4 3 2 1
6
1 1
1 2
1 3
1 4
1 5
1 6

*/