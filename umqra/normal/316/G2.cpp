#include <iostream>
#include <cstring>
#include <set>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int CNT = 2;
const int A = 27;
const int N = (int)1e5;
const int M = (int)2e7;
const int mod[] = {(int)1e9 + 7, (int)1e9 + 9};
const int pr = 12381;

char str[N], p[N], limit[N];
int leftB[10][N], rightB[10][N];
bool used[M];

int mv = 0;

struct Node
{
	int len;
	Node *suff;
	bool term;
	int id;
	int cnt;
	Node *go[A];
	Node () 
	{
		cnt = 0;
		id = mv++;
		len = 0;
		term = false;
		suff = NULL;                
		for (int i = 0; i < A; i++) go[i] = NULL;
	} 
	Node (int len_)
	{
		cnt = 0;
		id = mv++;
		len = len_;
		term = false;
		suff = NULL;                
		for (int i = 0; i < A; i++) go[i] = NULL;
	}
};

struct PolyHash
{
	int p[CNT];
	PolyHash () {}
	PolyHash (ll x)
	{
		for (int i = 0; i < CNT; i++)
			p[i] = (x % (ll)mod[i]);
	}
	void operator += (const PolyHash &a)
	{
		for (int i = 0; i < CNT; i++)
		{
			p[i] += a.p[i];
			if (p[i] >= mod[i])
				p[i] -= mod[i];  
		}
	}
	void operator *= (const PolyHash &a)
	{
		for (int i = 0; i < CNT; i++)
		{
			p[i] = ((ll)p[i] * (ll)a.p[i]) % (ll)mod[i];
		}
	}
	void operator -= (const PolyHash &a)
	{
		for (int i = 0; i < CNT; i++)
		{
			p[i] -= a.p[i];
			if (p[i] < 0)
				p[i] += mod[i];
		}
	}
	bool operator < (const PolyHash &a) const
	{                                        
		for (int i = 0; i < CNT; i++)
		{
			if (a.p[i] != p[i])
				return p[i] < a.p[i];
		}
		return false;
	}
} Hash[N], deg[N];
set <PolyHash> allStr;

typedef Node* Node_ptr;

struct SuffixA
{
	Node_ptr root;
	Node_ptr last;
	SuffixA ()
	{
		root = new Node();
		last = root;
	}
};


int getId(Node_ptr v)
{
	if (v == NULL)
		return -1;
	return v -> id;
}

void printTree(Node_ptr v)
{
	if (v == NULL || used[v -> id])
		return;
	used[v -> id] = 1;
	printf("ID = %d, suff = %d\nGo: ", v -> id, getId(v -> suff));
	for (int i = 0; i < 3; i++)
	{
		printf("%c:%d ", ('a' + i), getId((v -> go)[i]));
	}
	puts("");
	for (int i = 0; i < 3; i++)
		printTree((v -> go)[i]);
}

Node_ptr addChar(int c, Node_ptr root, Node_ptr last)
{
	Node_ptr newL = new Node(last -> len + 1);
	Node_ptr p;
	for (p = last; p != NULL && (p -> go)[c] == NULL; p = p -> suff)
		(p -> go)[c] = newL;	     

	if (p == NULL)
		newL -> suff = root;
	else
	{
		Node_ptr q = (p -> go)[c];
		if (q -> len == p -> len + 1)
			newL -> suff = q;
		else
		{
			Node_ptr clone = new Node(p -> len + 1);
			for (int i = 0; i < A; i++) (clone -> go)[i] = (q -> go)[i];
			for (;p != NULL && (p -> go)[c] == q; p = p -> suff) (p -> go)[c] = clone;
			clone -> suff = q -> suff;
			newL -> suff = q -> suff = clone;
		}
	}
	return newL;
}

SuffixA buildSuffixA(char *s, int len)
{
	SuffixA res = SuffixA();
	for (int i = 0; i < len; i++)
		res.last = addChar(s[i] - 'a', res.root, res.last);

	return res;
}

void calcTerm(SuffixA cur)
{
	Node_ptr p = cur.last;
	while (p != NULL)
	{
		p -> term = true;
		p = p -> suff;
	}
}

void calcCnt(Node_ptr v)
{                            
	if (used[v -> id])
		return;
	if (v -> term)
		v -> cnt = 1;
	used[v -> id] = 1;
	for (int i = 0; i < A; i++)
	{
		Node_ptr to = (v -> go)[i];
		if (to != NULL)
		{
			calcCnt(to);
			v -> cnt += to -> cnt;
		}
	}
}

void calcCnt(SuffixA cur)
{
	calcCnt(cur.root);
}

int getCnt(Node_ptr v1, Node_ptr v2, int c)
{
	return ((v1 -> go)[c] -> cnt) - ((v2 -> go)[c] -> cnt);
}

Node_ptr getPosWithoutLast(Node_ptr v, int len)
{
	if (v -> suff == NULL)
		return v;
	if ((v -> suff) -> len == len - 1)
		return v -> suff;
	return v;
}

void updateLimitPos(SuffixA lim, SuffixA strA, char *s, int len, int l, int r, int *lB, int *rB)
{          
	Node_ptr limPos = lim.root;
	Node_ptr strPos = strA.root;
	int curB = 0;
	for (int i = 0; i < len; i++)
	{                                 
		curB = max(i, curB);
		while (curB < len && getCnt(limPos, strPos, s[curB] - 'a') > r)
		{
			limPos = (limPos -> go)[s[curB] - 'a'];
			strPos = (strPos -> go)[s[curB] - 'a'];
			curB++;
		}
		lB[i] = curB - 1;
		limPos = getPosWithoutLast(limPos, curB - i);
		strPos = getPosWithoutLast(strPos, curB - i);

	}
	limPos = lim.root;
	strPos = strA.root;
	curB = 0;                      
	for (int i = 0; i < len; i++)
	{
		curB = max(i, curB);
		while (curB < len && getCnt(limPos, strPos, s[curB] - 'a') >= l)
		{           
			cerr << getCnt(limPos, strPos, s[curB] - 'a') << ":" << l << endl;;
			limPos = (limPos -> go)[s[curB] - 'a'];
			strPos = (strPos -> go)[s[curB] - 'a'];                        
			curB++;
		}                    
		rB[i] = curB - 1;
		limPos = getPosWithoutLast(limPos, curB - i);
		strPos = getPosWithoutLast(strPos, curB - i);    
	}
	cerr << "----------------" << endl;
}
            
void calcDeg()
{
	deg[0] = PolyHash(1);
	for (int i = 1; i < N; i++)
	{
		deg[i] = PolyHash(pr);
		deg[i] *= deg[i - 1];
	}
}

void calcHash(char *s, int len)
{
	Hash[0] = PolyHash(s[0] - 'a' + 1);
	for (int i = 1; i < len; i++)
	{
		Hash[i] = PolyHash(s[i] - 'a' + 1);
		Hash[i] *= deg[i];
		Hash[i] += Hash[i - 1];
	}
}

PolyHash getHash(int a, int b)
{
	PolyHash res = Hash[b];
	if (a > 0)
		res -= Hash[a - 1];
	res *= deg[N - a - 1];
	return res;
}
         
int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	scanf("%s%d", str, &n);
	int lenStr = strlen(str);  

	calcDeg();
	calcHash(str, lenStr);

	SuffixA strA = buildSuffixA(str, lenStr);

//	cerr << "Build tree: success!" << endl;
	calcTerm(strA);
//	cerr << "Calc terminal: success!" << endl;
	calcCnt(strA);
//	cerr << "Calc count: success!" << endl;
                            
	for (int i = 0; i < n; i++)
	{
		int l, r;
		scanf(" %s%d%d", p, &l, &r); 
//		cerr << "String: " << p << endl;
		int lenP = strlen(p);
		copy(str, str + lenStr, limit);
		limit[lenStr] = 'z' + 1;
		copy(p, p + lenP, limit + lenStr + 1);
		limit[lenStr + lenP + 1] = 0;      
		SuffixA curA = buildSuffixA(limit, lenStr + lenP + 1);
//		cerr << "Build tree: success!" << endl;
		calcTerm(curA);
//		cerr << "Calc terminal: success!" << endl;
		calcCnt(curA);  
//		cerr << "Calc count: success!" << endl;
//		cerr << strA.root << endl;
		updateLimitPos(curA, strA, str, lenStr, l, r, leftB[i], rightB[i]);
//		cerr << "Update limits: success!" << endl;
	}

	int ans = 0;
	for (int i = 0; i < lenStr; i++)
	{
		int curL = i - 1, curR = lenStr - 1;
		for (int s = 0; s < n; s++)
		{
			curL = max(curL, leftB[s][i]);
			curR = min(curR, rightB[s][i]);
		}                           
		for (int s = curL + 1; s <= curR; s++)
		{
			PolyHash curH = getHash(i, s);
			if (allStr.find(curH) == allStr.end())
			{
				ans++;
				allStr.insert(curH);
			}
		}
	}

	printf("%d", ans);

	return 0;
}