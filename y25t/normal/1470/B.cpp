#include<cstdio>
#include<algorithm>
#include<vector>
#define N 300005
#define M 1000005

int T;

int n,a[N];

int pr[M],_pr;
bool np[M];
inline void si(int x){
	for(int i=2;i<=x;i++){
		if(!np[i])
			pr[++_pr]=i;
		for(int j=1;j<=_pr&&pr[j]*i<=x;j++){
			np[pr[j]*i]=1;
			if(i%pr[j]==0)
				break;
		}
	}
}

int b[M];
std::vector<int> vec;

int q;

int main(){
	si(1000000);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		vec.clear();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			int tmp=1;
			for(int j=1;j<=_pr&&pr[j]*pr[j]<=a[i];j++)
				if(a[i]%pr[j]==0){
					int cnt=0;
					while(a[i]%pr[j]==0){
						a[i]/=pr[j];
						cnt++;
					}
					if(cnt&1)
						tmp*=pr[j];
				}
			if(a[i]>1)
				tmp*=a[i];
			b[tmp]++;
			vec.push_back(tmp);
		}
		int s0=0,s1=0,ans0=0,ans1=0;
		for(auto i:vec){
			if(i==1){
				s0+=b[i];
				s1+=b[i];
			}
			else if(b[i]&1){
				ans0=std::max(ans0,b[i]);
				ans1=std::max(ans1,b[i]);
			}
			else{
				ans0=std::max(ans0,b[i]);
				s1+=b[i];
			}
			b[i]=0;
		}
		ans0=std::max(ans0,s0);
		ans1=std::max(ans1,s1);
		scanf("%d",&q);
		while(q--){
			int x;
			scanf("%d",&x);
			printf("%d\n",x?ans1:ans0);
		}
	}
}