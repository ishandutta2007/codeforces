#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <assert.h>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD2 1000000007
#define MOD 1048575
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 100500
#define SUM 23423
#define MAG 1048576
#define OPEN 0
#define CLOSE 1
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,cur_x,cur_y;
ll a[200500];
ll used[305][305];
ll d[305][305][32][8];
ll dir_arr[8][2] = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
struct magic {
	int x,y,step,dir;
	magic()
	{
	}
	magic(ll x, ll y, ll step, ll dir)
	{
		this -> x = x;
		this->y = y;
		this->step = step;
		this->dir = dir;
	}
};
magic f[1050000];
string s;
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
	for (i = 0; i < n; i++)
  		cin >> a[i];
	a[0]--;
	d[152][152][0][0] = 1;
	ll sz = 0;
	f[sz++] = magic(152,152,0,0);
	i = 0;
	while (i != sz)
	{
		magic tmp = f[i];
		used[tmp.x][tmp.y] = 1;
		ll dir = tmp.dir;
		ll step = tmp.step;
		ll x = tmp.x;
		ll y = tmp.y;
		i = ((i+1)&MOD);
		if (step == n)
		   continue;
		for (int j = 0; j < a[step]; j++)
		{
			x += dir_arr[dir][0];
			y += dir_arr[dir][1];
			used[x][y] = 1;

			//cout << x << " " << y << endl;
		}
		if (!d[x][y][step+1][(dir+1)&7])
		{
		   d[x][y][step+1][(dir+1)&7] = 1;
		   f[sz] = magic(x,y,step+1,((dir+1)&7));
		   sz = ((sz+1)&MOD);
		}
		if (!d[x][y][step+1][(dir+7)&7])
		{
		   d[x][y][step+1][(dir+7)&7] = 1;
		   f[sz] = magic(x,y,step+1,((dir+7)&7));
		   sz = ((sz+1)&MOD);
		}
	}
	for (i = 0; i < 305; i++)
		for (j = 0; j < 305; j++)
			m += used[i][j];
	cout << m << endl;
    return 0;
}