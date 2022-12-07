#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=1005;
int n,m;
int l[N],r[N],f[N];
int main(){
	scanf("%d",&n);
	for (m=0;1<<m<n;m++);
	For(i,2,n) l[i]=1,r[i]=(1<<m)-1;
	Rep(k,m,2) For(T,0,1){
		//For(i,1,n) cout<<l[i]<<' '<<r[i]<<endl;
		printf("?");
		For(i,1,n)
			if (l[i]==r[i]&&((l[i]>>k)&1)==T)
				printf(" %d",1<<(k-1));
			else printf(" %d",0);
		puts("");
		fflush(stdout);
		string s;
		cin>>s;
		s='0'+s;
		
		printf("?");
		For(i,1,n)
			if (l[i]==r[i]&&((l[i]>>k)&1)==T)
				printf(" %d",(1<<(k-1))-1);
			else printf(" %d",0);
		puts("");
		fflush(stdout);
		string t;
		cin>>t;
		t='0'+t;
		
		For(i,1,n)
			if (l[i]!=r[i]&&(((l[i]-1)>>k)&1)==T){
				assert(s[i]>=t[i]);
				if (s[i]=='0') l[i]+=1<<(k-1);
				else if (t[i]=='1') r[i]-=1<<(k-1);
				else l[i]=r[i]=(l[i]+r[i])/2;
			}
	}
	For(i,1,n)
		assert(l[i]==r[i]);
	For(p,0,2){
		int q=(p+1)%3;
		For(k,0,m-1){
			printf("?");
			For(i,1,n)
				if (l[i]%3==p&&((i-1)&(1<<k)))
					printf(" 1");
				else printf(" 0");
			puts("");
			fflush(stdout);
			string s;
			cin>>s;
			s='0'+s;
			
			For(i,1,n)
				if (l[i]%3==q&&s[i]=='1')
					f[i]|=1<<k;
		}
	}
	printf("!\n");
	For(i,2,n) printf("%d %d\n",i,f[i]+1);
}
/*
5
11111
11111
00000
00000
11111
10011
00000
00000
10011
00000
00000
10001
00000
11111


*/