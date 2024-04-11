#include<bits/stdc++.h>
using namespace std;

const int N=300005;
int n,m,X;
int x[N],y[N],fa[N],q[N];
vector<pair<int,int> > v[N];
set<int> S;
long long a[N];

int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}

void Merge(int x,int y){
	x=get(x); y=get(y);
	if (v[x].size()<v[y].size()) swap(x,y);
	if (a[x]>=X) S.erase(x);
	if (a[y]>=X) S.erase(y);
	fa[y]=x;
	for (auto i:v[y])
		v[x].push_back(i);
	a[x]=a[x]+a[y]-X;
	if (a[x]>=X) S.insert(x);
}
int main(){
	scanf("%d%d%d",&n,&m,&X);
	long long rem=1ll*(n-1)*X;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		rem-=a[i];
	}
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x[i],&y[i]);
		if (get(x[i])!=get(y[i])){
			fa[get(x[i])]=get(y[i]);
			v[x[i]].push_back(pair<int,int>(y[i],i));
			v[y[i]].push_back(pair<int,int>(x[i],i));
			q[++*q]=i;
		}
	}
	if (rem>0){
		puts("NO");
		return 0;
	}
	puts("YES");
	rem=n-1;
	for (int i=1;i<=n;i++)
		if (a[i]>=X) S.insert(i);
	for (int i=1;i<=n;i++) fa[i]=i;
	int p=1;
	for (int i=1;i<n;i++){
		if (S.size()){
			int x=*S.begin();
			for (;v[x].size();){
				int y=v[x].back().first;
				//cout<<x<<' '<<y<<endl;
				if (get(x)!=get(y)){
					printf("%d\n",v[x].back().second);
					Merge(x,y);
					break;
				}
				else
					v[x].pop_back();
			}
		}
		else{
			for (;;++p)
				if (get(x[p])!=get(y[p])){
					printf("%d\n",p);
					Merge(x[p],y[p]);
					break;
				}
		}
	}
}