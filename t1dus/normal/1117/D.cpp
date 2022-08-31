/*input

*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 1000000007
#define F first
#define S second
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FORD(i,a,b) for(int i=(a);i>=b;i--)
#define all(v) v.begin(),v.end()
#define itr ::iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define remin(a,b) (a) = min((a),(b))
#define remax(a,b) (a) = max((a),(b))

int n,m;
const int SZ = 105;

int add(int a, int b)
{
	int res = a + b;
	if(res >= MOD)
		return res - MOD;
	return res;
}

int mult(int a, int b)
{
	long long res = a;
	res *= b;
	if(res >= MOD)
		return res % MOD;
	return res;
}

struct matrix
{
	int arr[SZ][SZ];

	void makezeros()
	{
		REP(i,SZ) REP(j,SZ) arr[i][j] = 0;
	}

	void reset()
	{
		makezeros();
		arr[0][0] = 1;
		arr[0][m-1] = 1;
		FOR(i,1,m) arr[i][i-1] = 1;
	}

	void makeiden()
	{
		makezeros();
		for(int i=0;i<m;i++)
		{
			arr[i][i] = 1;
		}
	}

	int res(){
		int ans = 0;
		REP(i,m) ans += arr[m-1][i];
		return ans%MOD;
	}

	matrix operator + (const matrix &o) const
	{
		matrix res;
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.arr[i][j] = add(arr[i][j], o.arr[i][j]);
			}
		}
		return res;
	}

	matrix operator * (const matrix &o) const
	{
		matrix res;
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.arr[i][j] = 0;
				for(int k=0;k<SZ;k++)
				{
					res.arr[i][j] = add(res.arr[i][j] , mult(arr[i][k] , o.arr[k][j]));
				}
			}
		}
		return res;
	}
};

matrix power(matrix a, int b)
{
	matrix res;
	res.makeiden();
	while(b)
	{
		if(b & 1)
		{
			res = res * a;
		}
		a = a * a;
		b >>= 1;
	}
	return res;
}

signed main() {
	cin >> n >> m;
	if(n < m){
		cout << "1\n";
		return 0;
	}
	matrix mat;
	mat.reset();
	mat = power(mat,n);
	cout << mat.res() << endl;
}