#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> prime;
int vis[10000001],n,arr[100000];
int chk[10000001];

int main() {
	for(int i=2;i<=10000000;i++) {
		if(!vis[i]) {
			prime.push_back(i);
			for(long long j = 1ll*i*i; j<=10000000; j+=i) {
				vis[j] = 1;
			}
		}
	}
	
	int val,f=0,k=2;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&val);
		if(f==0) {
			if(!chk[val]) {
				printf("%d ",val);
				for(int i=0;i<prime.size();i++) {
					if(prime[i] * prime[i] > val || prime[i] > 350) break;
					if(val % prime[i]!=0) continue;
					for(int j=prime[i];j<=10000000; j+=prime[i]) chk[j]=1;
					while(val % prime[i] == 0) val /= prime[i];
				}
				if(val != 1) {
					for(int j = val; j<=10000000; j+=val) chk[j] = 1;
				}
			}
			else {
				int t;
				f=1;
				for(t=val;chk[t];t++);
				chk[t] = 1;
				printf("%d ",t);

				val = t;
				for(int i=0;i<prime.size();i++) {
					if(prime[i] * prime[i] > val) break;
					if(val % prime[i] != 0) continue;
					for(int j=prime[i];j<=10000000; j+=prime[i]) chk[j]=1;
					while(val % prime[i] == 0) val /= prime[i];
				}
				if(val != 1) {
					for(int j = val; j<=10000000; j+=val) chk[j] = 1;
				}
				continue;
			}
		}
		if(f) {
			for(;chk[k];k++);
			printf("%d ",k);
			chk[k]=1;

			val = k;
			for(int i=0;i<prime.size();i++) {
				if(prime[i] * prime[i] > val) break;
				if(val % prime[i] != 0) continue;
				for(int j=prime[i];j<=10000000; j+=prime[i]) chk[j]=1;
				while(val % prime[i] == 0) val /= prime[i];
			}
			if(val != 1) {
				for(int j = val; j<=10000000; j+=val) chk[j] = 1;
			}
		}
	}

	return 0;
}