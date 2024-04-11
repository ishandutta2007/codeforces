#include <bits/stdc++.h>
 
#define fr(a,init,end) for(int a = init; a < end; a++)
#define fre(i, u) for(int i = adj[u]; i != -1; i = ant[i])
#define sc(a) scanf("%d", &a)
#define debug(x) cerr << ">>> " << #x << " = " << x << endl;
#define dbg(x) if(1) cerr << ">>> " << x << endl;
#define _ << " , " <<
#define c_ std::ios::sync_with_stdio(false);
 
 
using namespace std;
 
typedef long long ll;

const ll inf = ll(1e17);
int n,m,k;
int arr[200];
int lit[200][200];
ll pd[200][200][200];
ll bt(int i, int beauty, int color)
{
	if(i == n && beauty == k) return 0;
	else if(i==n) return inf;
	else if(arr[i]!=0 && arr[i] != color) return inf;
	
	if(pd[i][beauty][color]!= -1) return pd[i][beauty][color];
	int prev_c = arr[i];
	arr[i] = color;
	ll &res = pd[i][beauty][color]; 
	res = inf;


	fr(j,1,m+1)
	{
		int newb = beauty+(i == n-1 || (arr[i]!=j));
		res = min(res, (prev_c == 0 ? lit[i][color] : 0)+bt(i+1, newb, j));
	}

	//printf("i %i, beauty %i, color %i is %lli\n",i,beauty,color,res);

	arr[i] = prev_c;
	return res;
}
 
int main()
{

 	cin >> n >> m >> k;
 	memset(pd,-1,sizeof pd);
 	fr(i,0,n)
 	{
 		cin >> arr[i];
 	}
 	fr(i,0,n)
 	{
 		fr(j,1,m+1)
 		{
 			cin >> lit[i][j];
 		}
 	}
 	ll r=inf;
 	fr(i,1,m+1)
 	{
 		r = min(r,bt(0,0,i));
 	}
 	cout << (r>=inf ? -1 : r) << endl;
    return 0;
}