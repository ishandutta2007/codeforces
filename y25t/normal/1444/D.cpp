#include<cstdio>
#include<algorithm>
#include<vector>
#include<bitset>
#define N 1005

int T;

int n,m,a[N],b[N];

std::bitset<N*N> f[N];

std::vector<int> a1,a2,b1,b2;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
			scanf("%d",&b[i]);
		if(n!=m){
			puts("No");
			continue;
		}
		int sum=0;
		for(int i=1;i<=n;i++)
			sum+=a[i];
		if(sum%2==1){
			puts("No");
			continue;
		}
		f[0][0]=1;
		for(int i=1;i<=n;i++)
			f[i]=f[i-1]|(f[i-1]<<a[i]);
		sum/=2;
		if(!f[n][sum]){
			puts("No");
			continue;
		}
		a1.clear();
		a2.clear();
		for(int i=n;i;i--)
			if(a[i]<=sum&&f[i-1][sum-a[i]]){
				sum-=a[i];
				a1.push_back(a[i]);
			}
			else
				a2.push_back(a[i]);
		sum=0;
		for(int i=1;i<=n;i++)
			sum+=b[i];
		if(sum%2==1){
			puts("No");
			continue;
		}
		sum/=2;
		f[0][0]=1;
		for(int i=1;i<=n;i++)
			f[i]=f[i-1]|(f[i-1]<<b[i]);
		if(!f[n][sum]){
			puts("No");
			continue;
		}
		b1.clear();
		b2.clear();
		for(int i=n;i;i--)
			if(b[i]<=sum&&f[i-1][sum-b[i]]){
				sum-=b[i];
				b1.push_back(b[i]);
			}
			else
				b2.push_back(b[i]);
		std::sort(a1.begin(),a1.end());
		std::sort(a2.begin(),a2.end());
		std::sort(b1.begin(),b1.end());
		std::sort(b2.begin(),b2.end());
		if(a1.size()>a2.size())
			std::swap(a1,a2);
		if(b1.size()<b2.size())
			std::swap(b1,b2);
		std::vector<int>::iterator i=a1.end(),j=b1.begin();
		int x=0,y=0,t1=1,t2=1;
		puts("Yes");
		while(n--){
			x+=t1*(*--i);
			printf("%d %d\n",x,y);
			y+=t2*(*j++);
			printf("%d %d\n",x,y);
			if(i==a1.begin()){
				t1=-1;
				i=a2.end();
			}
			if(j==b1.end()){
				t2=-1;
				j=b2.begin();
			}
		}
	}
}