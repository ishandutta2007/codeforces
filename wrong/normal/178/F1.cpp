#include<cstdio>
#include<vector>

using namespace std;

int n, k;

struct trie {
  int cnt, whole;
  trie *next[26];
  trie() {
    cnt = 0;
    for(int i=0; i<26; ++i)
      next[i] = NULL;
  }
} *root = new trie();

void ins(char *s)
{
  trie *p = root;
  for(int i=0; s[i]; ++i) {
    int c = s[i]-'a';
    if(p->next[c] == NULL)
      p->next[c] = new trie();
    p = p->next[c];
  }
  p->cnt++;
}

vector<int> *dp(trie *p, int dep)
{
  int pos = -1, cnt = 0;
  for(int i=0; i<26; ++i) {
    if(p->next[i] != NULL) {
      pos = i;
      cnt++;
    }
  }
  if(cnt == 0) {
    vector<int> *ret = new vector<int>(p->cnt+1);
    for(int i=0; i<=p->cnt; ++i)
      (*ret)[i] = i*(i-1)*dep/2;
    return ret;
  } else if(cnt == 1 && p->whole == p->next[pos]->whole) {
    return dp(p->next[pos], dep+1);
  } else {
    vector<int> *ret = new vector<int>(p->whole+1, 0);
    for(int i=0; i<=p->cnt; ++i)
      (*ret)[i] = i*(i-1)*dep;
    int lim = p->cnt;
    for(int i=0; i<26; ++i) {
      if(p->next[i] != NULL) {
	vector<int> *tmp = dp(p->next[i], dep+1);
	for(int j=lim; j>=0; --j)
	  for(int k=1; k<(int)tmp->size() && j+k<=lim+p->next[i]->whole; ++k)
	    (*ret)[j+k] = max((*ret)[j+k], (*ret)[j] + (*tmp)[k] + (j*k*dep));
	lim += p->next[i]->whole;
      }
    }
    return ret;
  }
}

int dfs(trie *p)
{
  p->whole = p->cnt;
  for(int i=0; i<26; ++i)
    if(p->next[i] != NULL)
      p->whole += dfs(p->next[i]);
  return p->whole;
}

int main()
{
  char s[512];
  scanf("%d%d", &n, &k);
  for(int i=0; i<n; ++i) {
    scanf("%s", s);
    ins(s);
  }
  dfs(root);
  printf("%d\n", (*dp(root, 0))[k]);
  return 0;
}