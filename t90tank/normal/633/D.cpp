#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std; 

const int maxn = 2000; 

map<int,int> S;
map<pair<int,int>,int> S2; 

bool g[maxn][maxn]; 
int a[maxn]; 
int n; 
int q[maxn*maxn];
int head, tail; 

int main() 
{
	memset( g, true, sizeof( g ) );
	scanf( "%d", &n );
	for (int i = 1; i <= n; ++i) scanf( "%d", &a[i] );
	S.clear(); S2.clear();  
	for (int i = 1; i <= n; ++i) S[a[i]]++; 
	int ans = 2; 
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= n; ++j) 
			if ( i != j ) 
			{ 
				S[a[i]]--; S[a[j]]--;
				head = 1; tail = 2; 
				q[1] = a[i]; q[2] = a[j]; 
				if ( S.count( a[j] - a[i] ) == 0 || S[a[j]-a[i]] == 0 ) 
				{
					while ( 1 ) 
					{
						int tmp = q[tail-1]+q[tail]; 
						while ( head + 1 < tail &&  ( S.count(tmp) == 0 || S[tmp] == 0 ) ) 
						{
							S[q[head]]++; 
							head++; 
						}
						if ( S.count(tmp) == 0 || S[tmp] == 0 ) break; 
						S[tmp]--;
						q[++tail] = tmp;
				//		for (int i = head; i <= tail; ++i) cout<<q[i]<<' '; 
				//		cout<<endl; 
						ans = max( ans, tail-head+1 );   
					}
				}
				for (int i = head; i <= tail; ++i) S[q[i]]++; 
			}
	int c = 0; 
	for (int i = 1; i <= n; ++i) 
		if ( a[i] == 0 ) ++c; 
	ans = max( ans , c ); 
	cout<<ans<<endl; 
}