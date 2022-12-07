#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

int n,t1,t2;
pair<int,int> q1[5005],q2[5005];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if ((i+j)&1)
				q1[++t1]=pair<int,int>(i,j);
			else
				q2[++t2]=pair<int,int>(i,j);
	for (;t1&&t2;){
		int c;
		scanf("%d",&c);
		if (c==1){
			printf("2 %d %d\n",q2[t2].first,q2[t2].second);
			--t2;
		}
		else{
			printf("1 %d %d\n",q1[t1].first,q1[t1].second);
			--t1;
		}
		fflush(stdout);
	}
	for (;t1;--t1){
		int c;
		scanf("%d",&c);
		printf("%d %d %d\n",(c==1?3:1),q1[t1].first,q1[t1].second);
		//--t1;
		fflush(stdout);
	}
	for (;t2;--t2){
		int c;
		scanf("%d",&c);
		printf("%d %d %d\n",(c==2?3:2),q2[t2].first,q2[t2].second);
		//--t2;
		fflush(stdout);
	}
}