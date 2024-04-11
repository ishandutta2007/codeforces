#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

typedef std::pair<int, int> ip;
int n,arr[1000001];
std::vector<ip> tmp[1000001];

inline int ABS(int val) {
	return val<0?-val:val;
}
int main() {
	scanf("%d",&n);
	
	long long sum=0,p=0,m=0;
	for(int i=1;i<=n;i++) {
		scanf("%d",arr+i);
		sum+=ABS(arr[i]-i);
		if(arr[i]>=i) {
			m++;
			if(arr[i]-i+1<n&&arr[i]!=n) tmp[arr[i]-i+1].push_back(ip(i,1));
		}
		else {
			p++;
			if(n-i+arr[i]+1<n) tmp[n-i+arr[i]+1].push_back(ip(i,1));
		}
		if(n-i+1<n) tmp[n-i+1].push_back(ip(i,2));
	}
	long long min=sum;
	int idx=0;
	for(int k=1;k<n;k++) {
		for(auto &it:tmp[k]) {
			if(it.second==1) {
				m--;p++;
			}
			else if(it.second==2) {
				if(arr[it.first]!=n) {
					p--;m++;
				}
				sum+=arr[it.first]-ABS(arr[it.first]-n);
			}
		}
		sum+=p-m;
		if(min>sum) {
			min=sum;
			idx=k;
		}
	}
	printf("%lld %d\n",min,idx);
	
	return 0;
}