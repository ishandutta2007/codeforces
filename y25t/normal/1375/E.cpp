#include<cstdio>
#include<algorithm>
#include<vector>
#define pii std::pair<int,int>
#define sec second
#define fir first
#define mpii std::make_pair
#define N 1005

int n,a[N];

pii val[N];

int b[N];

std::vector<pii> ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		val[i]=mpii(a[i],i);
	}
	std::sort(val+1,val+n+1);
	for(int i=1;i<=n;i++)
		b[std::lower_bound(val+1,val+n+1,mpii(a[i],i))-val]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<n;j++)
			if(b[j]>b[j+1]){
				std::swap(b[j],b[j+1]);
				ans.push_back(mpii(b[j],b[j+1]));
			}
	printf("%d\n",ans.size());
	for(std::vector<pii>::iterator it=ans.begin();it!=ans.end();it++)
		printf("%d %d\n",it->fir,it->sec);
}