#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second 
#define PB push_back
#define ll long long
using namespace std;

const int N=1505;

pii O;
int n,Q,a[N][N];
vector<pii> v[2][N];

int Dist(const pii &x,const pii &y){
	return max(y.fi-x.fi,y.se-x.se);
}
bool cmp(const pii &x,const pii &y){
	return Dist(O,x)<Dist(O,y);
}
int ans[N];
int vi[N*N];
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) For(j,1,n) scanf("%d",&a[i][j]);
	int pre=0,suf=1;
	Rep(i,n,1){
		swap(pre,suf);
		Rep(j,n,1){
			v[suf][j].resize(0);
			if (i==n||j==n){
				v[suf][j].PB(pii(i,j));
				ans[1]++;
			}
			else{
				vector<pii> temp;
				temp.PB(pii(i,j));
				for (auto k:v[pre][j+1]) temp.PB(k);
				for (auto k:v[suf][j+1]) temp.PB(k);
				for (auto k:v[pre][j  ]) temp.PB(k);
				O=pii(i,j);
				sort(temp.begin(),temp.end(),cmp);
				
				int rem=Q+1;
				for (auto k:temp)
					if (!vi[a[k.fi][k.se]]&&rem){
						//cout<<i<<' '<<j<<' '<<k.fi<<' '<<k.se<<endl;
						vi[a[k.fi][k.se]]=1;
						v[suf][j].PB(k);
						--rem;
					}
				for (auto k:temp)	
					vi[a[k.fi][k.se]]=0;
					
				if (!rem)
					++ans[min(min(n-i+1,n-j+1),Dist(pii(i,j),v[suf][j].back()))];
				else
					++ans[min(n-i+1,n-j+1)];
			}
		}
	}
	
	Rep(i,n,1)
		ans[i]+=ans[i+1];
	For(i,1,n)
		printf("%d ",ans[i]);
}