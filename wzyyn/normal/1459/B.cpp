#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",(n/2+1)*(n-n/2+1)*(n%2==0?1:2));
}