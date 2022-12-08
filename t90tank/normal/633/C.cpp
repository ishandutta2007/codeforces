#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std; 

struct data 
{
	int c[30]; 
	vector<int> d;
	int f;  
//	int fa,pre;  
//	int now; 
}e[1200000];
int tot;  

char st[120000]; 
int len; 
vector<char> ans[120000]; 

void Ins( int flag, int T, int x ) 
{
	if ( x == len ) 
	{ 
		e[T].f = flag; 
		return; 
	}
	if ( e[T].c[st[x]-'a'] == 0 ) 
	{
		e[++tot] = e[0];   
		e[T].c[st[x]-'a'] = tot; 	
	}	
	Ins( flag, e[T].c[st[x]-'a'], x+1 );
}

char ss[200000]; 
bool f[200000]; 
int g[200000]; 

int main() 
{
	int n;
	cin>>n;  
	scanf( "%s", ss+1 ); 
	int m; 
	cin>>m;
	tot = 1;
	memset( e, 0, sizeof( e ) );  
	for (int i = 1; i <= m; ++i) 
	{
		scanf( "%s", st ); 
		len = strlen( st );
		ans[i].clear();  
		for (int j = 0; j < len; ++j)
		{ 
			ans[i].push_back( st[j] ); 
			if ( st[j] < 'a' ) st[j] += 'a' - 'A';
		}
		Ins( i, 1, 0 ); 
	}
	memset( f, false, sizeof( f ) ); 
	f[0] = true; 
	for (int i = 1; i <= n; ++i)
	{
		int x = 1; 
		for (int j = i; j > 0 && x != 0; --j)
		{
			x = e[x].c[ss[j]-'a'];
			if (e[x].f != 0 && f[j-1] ) 
			{
				f[i] = true; 
				g[i] = e[x].f;
//				cout<<"?"<<endl; 
			}
//			cout<<x<<endl; 
		} 
//		cout<<endl; 
	}
//	cout<<"F"<<endl; 
	int x = n; 
	vector<char> uu;
	while ( x != 0 ) 
	{
	//	cout<<f[x]<<endl; 
		for (int i=ans[g[x]].size()-1; i>=0; --i) 
			uu.push_back( ans[g[x]][i] ); 
		//printf( "%c", ans[g[x]][i] ); 
		x -= ans[g[x]].size(); 
		if ( x != 0 ) uu.push_back( ' ' ); 
	}
	for (int i = uu.size()-1; i >= 0; --i) printf( "%c", uu[i] ); 
	printf( "\n" ); 
}