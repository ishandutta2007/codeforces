#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = (int)3e5 + 10;
const int M = 670;
const int STEP = 450;

struct Query
{
	int t, a, b;
	void scan()
	{
		scanf("%d%d%d", &t, &a, &b);
	}
} q[N];

struct Sqrt
{
	ll ans, sumSuff, sumPref;
	int cnt;
	Sqrt () {}	
	Sqrt (ll ans, ll sumPref, ll sumSuff, int cnt) : ans(ans), sumPref(sumPref), sumSuff(sumSuff), cnt(cnt) {}
} info[M];

int startX[N];
int curX[N];
int allX[N];
bool exist[N];
bool startD[N];
int indX;
int n, m;

int myLower(int x)
{
	int l = -1, r = indX;
	while (r - l > 1)
	{	
		int m = (l + r) / 2;
		if (allX[m] <= x)
			l = m;
		else
			r = m;
	}
	return l;
}

int myUpper(int x)
{
	int l = -1, r = indX;
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		if (allX[m] >= x)
			r = m;
		else
			l = m;
	}
	return r;
}

int getX(int x)
{       
	int res = myLower(x);
	if (res == -1 || allX[res] != x)
		throw;
	return res;
}

void getInput()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &startX[i]);
		curX[i] = startX[i];
		allX[indX++] = startX[i];
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		q[i].scan();
		if (q[i].t == 1)
		{
			curX[q[i].a - 1] += q[i].b;
			allX[indX++] = curX[q[i].a - 1];
		}
	}
	for (int i = 0; i < n; i++)
		curX[i] = startX[i];
}                   

void compressCoord()
{                       	
	sort(allX, allX + indX);
	indX = unique(allX, allX + indX) - allX;
}                       	

void fillExist()
{
	for (int i = 0; i < n; i++)
	{
		int curInd = getX(startX[i]);
		exist[curInd] = 1;
	}
}

int getCountPoint(int stX)
{
	int cnt = 0;
	for (int i = stX; i < stX + STEP; i++)
		if (exist[i])
			cnt++;
	return cnt;
}

int getCountPoint(int stX, int endX)
{
	int cnt = 0;
	for (int i = stX; i <= endX;)
	{
		if (startD[i])
		{
			if (i + STEP <= endX)
			{
				cnt += info[i / STEP].cnt;
				i += STEP;
			}
			else
			{
				cnt += exist[i];
				i++;
			}
		}
		else
		{
			cnt += exist[i];
			i++;
		}	
	}
	return cnt;
}

void calcDecomposition(int stX)
{
	if (stX + STEP >= indX)
		return;

	int cntL = 0;
	int cntR = getCountPoint(stX);

	startD[stX] = 1;
	int leftBord = allX[stX];
	int rightBord = allX[stX + STEP];
	ll sumSuff = 0, sumPref = 0;
	ll locAns = 0;
	int lastX = -1;
	for (int x = stX; x < stX + STEP; x++)
	{
		if (exist[x])
		{
			if (lastX != -1)
				locAns += (ll)(allX[x] - allX[lastX]) * (ll)cntR * (ll)cntL;
			cntR--;
			cntL++;
			lastX = x;
			sumSuff += (ll)rightBord - (ll)allX[x];
			sumPref += (ll)allX[x] - (ll)leftBord;
		}
	}
	int indDec = stX / STEP;                                                                                   
	info[indDec] = Sqrt(locAns, sumPref, sumSuff, cntL + cntR);
}

void fillDecomposition()
{
	for (int i = 0; i < indX; i += STEP)
		calcDecomposition(i);
}

int getStart(int x)
{
	return (x / STEP) * STEP;
}

void changePoint(int indP, int d)
{
	int oldX = curX[indP];
	int newX = oldX + d;
	curX[indP] = newX;
	exist[getX(oldX)] = 0;
	exist[getX(newX)] = 1; 
	calcDecomposition(getStart(getX(oldX)));
	calcDecomposition(getStart(getX(newX)));
}

void getAnswer(int l, int r)
{                  
	ll res = 0;
	int x;
	int cntL = 0, cntR = getCountPoint(l, r);
	int lastX = -1;
	for (x = l; x <= r && !startD[x]; x++)
	{                
		if (exist[x])
		{                          
			if (lastX != -1)
				res += (ll)(allX[x] - allX[lastX]) * (ll)cntL * (ll)cntR;
			cntL++;
			cntR--;
			lastX = x;
		}
	}            
	if (x + STEP < r)
	{         
		res += (ll)(allX[x] - allX[lastX]) * (ll)cntL * (ll)cntR;
		int indSq = x / STEP;
		for (;x + STEP <= r; x += STEP)
		{
			cntR -= info[indSq].cnt;
			res += info[indSq].ans;
			int lenSq = (allX[x + STEP] - allX[x]);
			res += (ll)lenSq * (ll)cntL * (ll)cntR;
			res += (ll)cntL * info[indSq].sumPref;
			res += (ll)cntR * info[indSq].sumSuff;
			cntL += info[indSq].cnt;
			indSq++;
		}

		lastX = x;
	}            
	for (;x <= r; x++)
	{                    
		if (exist[x])
		{                 
			res += (ll)(allX[x] - allX[lastX]) * (ll)cntL * (ll)cntR;
			cntL++;
			cntR--;
			lastX = x;
		}
	}              
	printf("%I64d\n", res);
}

void processQuery()
{
	for (int i = 0; i < m; i++)
	{                      
		if (q[i].t == 1)
			changePoint(q[i].a - 1, q[i].b);
		else
		{
			int l = myUpper(q[i].a);
			int r = myLower(q[i].b);
			getAnswer(l, r);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

    getInput();
    compressCoord();    	
    fillExist();
    fillDecomposition();
    processQuery();
  
    return 0;
}