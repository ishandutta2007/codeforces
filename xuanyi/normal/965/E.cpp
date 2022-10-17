#include <set>
#include <cstdio>
#include <algorithm>
const int MAXN = 100005 ;

template <typename T>
inline T max(const T x, const T y)
{
	return x < y ? y : x ;
}

int n, cnt, ANS ;
char s[MAXN] ;

struct tnode
{
	bool flg ;
	tnode *son[26] ;
	tnode()
	{
		flg = 0 ;
		for (int i = 0 ; i < 26 ; i++) son[i] = NULL ;
	}
} ;

typedef tnode* pnode ;

pnode root ;

typedef std :: multiset <int> tans ;
typedef tans* pans ;

pans merge(pans a, pans b)
{
	if (a->size() > b->size()) swap(a, b) ;
	for (tans :: iterator i = a->begin() ; i != a->end() ; i++)
	{
		b -> insert(*i) ;
	}
	delete a ;
	return b ;
}

pans calc(pnode cur, int curd)
{
	pans ans = new tans ;
	for (int i = 0 ; i < 26 ; i++)
		if (cur->son[i] != NULL)
		{
			pans t = calc(cur->son[i], curd+1) ;
			ans = merge(ans, t) ;
		}
	if (cur->flg) ans->insert(curd) ;
	else if (curd != 0)
	{
		ans->erase(--(ans->end())) ;
		ans->insert(curd) ;
	}
	return ans ;
}

int main()
{
	root = new tnode() ;
	scanf("%d", &n) ;
	for (int i = 1 ; i <= n ; i++)
	{
		scanf("%s", s) ;
		pnode cur = root ;
		char *t = s ;
		while (*t != '\0')
		{
			if (cur->son[*t - 'a'] == NULL) cur->son[*t-'a'] = new tnode() ;
			cur = cur->son[*t - 'a'] ;
			t++ ;
		}
		cur->flg = 1 ;
	}
	pans ans = calc(root, 0) ;
	for (tans :: iterator i = ans->begin() ; i != ans->end() ; i++)
	{
		ANS += *i ;
	}
	printf("%d\n", ANS) ;
	return 0 ;
}