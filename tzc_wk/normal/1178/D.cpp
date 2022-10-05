#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD			1000000007
#define FOR(i,l,r)	for(int i=l;i<=r;i++)
#define REP(i,n)	for(int i=1;i<=n;i++)
#define REP0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
#define MAKE1(a)	int a;
#define MAKE2(a,b)	int a,b;
#define MAKE3(a,b,c) int a,b,c;
#define MAKE4(a,b,c,d) int a,b,c,d;
#define DR1(a)		MAKE1(a);cin>>a;
#define DR2(a,b)	MAKE2(a,b);cin>>a>>b;
#define DR3(a,b,c)	MAKE3(a,b,c);cin>>a>>b>>c;
#define DR4(a,b,c,d) MAKE4(a,b,c,d);cin>>a>>b>>c>>d;
int pri[10005],prime[10005];
void init(){
	for(long long i=2;i<=10000;i++){
		if(!prime[i])	pri[++pri[0]]=i;
		for(long long j=1;j<=pri[0]&&pri[j]<=10000/i;j++){
			prime[pri[j]*i]=1;
			if(i%pri[j]==0)	break;
        }
    }
}
int n;
vector<int> g[1005];
int main(){
	init();
	cin>>n;
	for(int i=1;i<=n;i++){
		int next=i+1;
		if(i==n)	next=1;
		g[i].push_back(next);
	}
	int tot=n;
	int mid=n/2,cur=1;
	while(prime[tot]){
		g[cur].push_back(cur+mid);
		cur++;tot++;
	}
	cout<<tot<<endl;
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++)
			printf("%d %d\n",i,g[i][j]);
	}
	return 0;
}