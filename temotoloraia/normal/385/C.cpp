#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N=1e7;
int p[N+5];
ll mas[N+5];
int main(){
	int n;
	cin>>n;
	for (int i=2;i*i<=N;i++)
	if (p[i]==0)
	for (int j=i*i;j<=N;j+=i)
	if (p[j]==0)
	p[j]=i;
	for (int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		mas[x]++;
	}
	for (int i=N;i>=2;i--)
	if (mas[i] && p[i]>0){
		int I=i;
		while (I%p[i]==0)I/=p[i];
		mas[I]+=mas[i];
		mas[p[i]]+=mas[i];
	}
	for (int i=N;i>=2;i--)
	if (p[i])mas[i]=0;
	for (int i=2;i<=N;i++)mas[i]+=mas[i-1];
	int m;
	cin>>m;
	while (m--){
		int l,r;
		scanf("%d%d",&l,&r);
		if (l>N){
			printf("0\n");
			continue;
		}
		if (r>N)r=N;
		printf("%lld\n",mas[r]-mas[l-1]);
	}
	return 0;
}