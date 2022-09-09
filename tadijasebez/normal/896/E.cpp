#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
const int S=317;
const int H=N/S+1;
int cnt[H][N],lzy[H],p[H][N],a[N],n,mx[H];
vector<int> tmp;
int Find(int B,int x){tmp.pb(x);return p[B][x]==0?x:p[B][x]=Find(B,p[B][x]);}
void Build(int B){
	int l=max(B*S,1),r=min((B+1)*S-1,n);
	mx[B]=0;
	for(int i=l;i<=r;i++){
		cnt[B][a[i]]++;
		mx[B]=max(mx[B],a[i]);
	}
}
void Break(int B){
	int l=max(B*S,1),r=min((B+1)*S-1,n);
	for(int i=l;i<=r;i++)
		a[i]=Find(B,a[i])+lzy[B];
	for(int i:tmp)cnt[B][i]=p[B][i]=0;
	lzy[B]=0;
	tmp.clear();
}
void Upd(int B,int x){
	if(mx[B]>=x*2){
		for(int i=1;i<=x;i++){
			int val=i-lzy[B];
			if(cnt[B][val]){
				p[B][val]=val+x;
				cnt[B][val+x]+=cnt[B][val];
				cnt[B][val]=0;
			}
		}
		lzy[B]-=x;
	}else if(mx[B]>x){
		for(int i=mx[B];i>x;i--){
			int val=i-lzy[B];
			if(cnt[B][val]){
				p[B][val]=val-x;
				cnt[B][val-x]+=cnt[B][val];
				cnt[B][val]=0;
			}
		}
	}
	if(mx[B]>x)mx[B]=max(x,mx[B]-x);
}
int main(){
	int q;
	scanf("%i %i",&n,&q);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]);
	for(int i=0;i*S<=n;i++)Build(i);
	while(q--){
		int t,l,r,x;
		scanf("%i %i %i %i",&t,&l,&r,&x);
		int L=l/S,R=r/S,ans=0;
		if(L==R){
			Break(L);
			if(t==1){for(int i=l;i<=r;i++)if(a[i]>x)a[i]-=x;}
			else{for(int i=l;i<=r;i++)if(a[i]==x)ans++;}
			Build(L);
		}else{
			Break(L);
			if(t==1){for(int i=l;i<(L+1)*S;i++)if(a[i]>x)a[i]-=x;}
			else{for(int i=l;i<(L+1)*S;i++)if(a[i]==x)ans++;}
			Build(L);
			if(t==1){for(int i=L+1;i<R;i++)Upd(i,x);}
			else{for(int i=L+1;i<R;i++)if(x-lzy[i]<N)ans+=cnt[i][x-lzy[i]];}
			Break(R);
			if(t==1){for(int i=R*S;i<=r;i++)if(a[i]>x)a[i]-=x;}
			else{for(int i=R*S;i<=r;i++)if(a[i]==x)ans++;}
			Build(R);
		}
		if(t==2)printf("%i\n",ans);
	}
	return 0;
}