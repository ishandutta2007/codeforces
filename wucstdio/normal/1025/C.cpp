#include <bits/stdc++.h>
#define F(i,a,b) for ( int i = a ; i<= b ; i++)

using namespace std;

const int N  = 100005;

int n , p = -1 , ans;
int a[N],f[N];
char s[N];

int main ( void ) {
	scanf("%s",s+1);
	n=strlen ( s + 1 );
	F ( i , 1 , n ) {
		if ( s[i] == s[i % n + 1] ) {
			p = i;
			break;
		}
	}
	if ( p == -1 ) {
		printf ( "%d\n" , n );
		return 0;
	}
	F ( i , 1 , n ) {
		int x=(p+i-1)%n+1;
		a[i]=(s[x]=='b');
	}
	f[1]=1;
	ans=1;
	F ( i , 2 , n ) {
		if(a[i]==a[i-1])f[i]=1;
		else f[i]=f[i-1]+1;
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}