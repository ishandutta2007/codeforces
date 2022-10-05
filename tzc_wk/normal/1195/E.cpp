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
#define int long long
int n,m,a,b,x,y,z;
int g[9000005],h[3005][3005];
struct node{
    int pos,x;
}mx[3005],mn[3005];
int head,tail;
int s[3005][3005];
signed main(){
	cin>>n>>m>>a>>b>>g[0]>>x>>y>>z;
	for(int i=1;i<=n*m;i++)	g[i]=(g[i-1]*x%z+y)%z;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			h[i][j]=g[(i-1)*m+j-1];
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)
//			cout<<h[i][j]<<" ";
//		cout<<endl;
//	}
    for(int j=1;j<=n;j++){
        head=1;tail=0;
        for(int i=1;i<=m;i++){
            if(head<=tail&&mn[head].pos<i-b+1)		head++;
            while(head<=tail&&mn[tail].x>h[j][i])	tail--;
            mn[++tail].pos=i;
			mn[tail].x=h[j][i];
            if(i-b+1>0)	s[j][i-b+1]=mn[head].x;
        }
    }
    for(int j=1;j<=m-b+1;j++){
        head=1;tail=0;
        for(int i=1;i<=n;i++){
            if(head<=tail&&mn[head].pos<i-a+1)		head++;
            while(head<=tail&&mn[tail].x>s[i][j])	tail--;
            mn[++tail].pos=i;
			mn[tail].x=s[i][j];
            if(i-a+1>0)	s[i-a+1][j]=mn[head].x;
        }
    }
    int ans=0;
    for(int i=1;i<=n-a+1;i++)
        for(int j=1;j<=m-b+1;j++)
        	ans+=s[i][j];
    cout<<ans<<endl;
	return 0;
}