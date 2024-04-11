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


int n,m,temp;
int arr[1010];
int pd[1010][1010];
bool bt(int p, int i)
{
	
	if(i==n)
	{
		return false;
	}
	if(pd[i][p] != -1) return pd[i][p];

	pd[i][p] = (arr[i]%m==p || bt(p,i+1) || bt((p-arr[i]+m)%m, i+1));

	//printf("trying p=%i i=%i, it is %s.\n",p,i,pd[i][p]?"true":"false");

	return pd[i][p];


}

int main()
{ c_
	cin >> n >> m;
	if(n > m)
		cout << "YES" << endl;
	else
	{
		fr(i,0,n)
		{
			cin >> temp;
			arr[i] = temp%m;
		}
		memset(pd,-1,sizeof pd);

		cout << (bt(0,0) ? "YES" : "NO") << endl;
	}
    return 0;
}